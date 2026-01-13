package ui

import (
	"fmt"
	"time"

	"file-processor/internal/processor"

	"fyne.io/fyne/v2"
	"fyne.io/fyne/v2/app"
	"fyne.io/fyne/v2/container"
	"fyne.io/fyne/v2/dialog"
	"fyne.io/fyne/v2/widget"
)

// RunGUI 启动GUI界面
func RunGUI() {
	myApp := app.NewWithID("file-processor")
	myApp.Settings().SetTheme(&myTheme{})
	myWindow := myApp.NewWindow("并发文件处理工具")
	myWindow.Resize(fyne.NewSize(800, 600))
	myWindow.CenterOnScreen()

	// 配置变量
	var config = &processor.Config{
		SourceDir:  "",
		TargetDir:  "",
		Operation:  "copy",
		Prefix:     "",
		Suffix:     "",
		NumWorkers: 4,
		Recursive:  false,
		VerifyMD5:  false,
	}

	// UI组件
	sourceLabel := widget.NewLabel("源目录: 未选择")
	targetLabel := widget.NewLabel("目标目录: 未选择")
	
	sourceBtn := widget.NewButton("选择源目录", func() {
		dialog.ShowFolderOpen(func(dir fyne.ListableURI, err error) {
			if err == nil && dir != nil {
				config.SourceDir = dir.Path()
				sourceLabel.SetText(fmt.Sprintf("源目录: %s", dir.Name()))
			}
		}, myWindow)
	})

	targetBtn := widget.NewButton("选择目标目录", func() {
		dialog.ShowFolderOpen(func(dir fyne.ListableURI, err error) {
			if err == nil && dir != nil {
				config.TargetDir = dir.Path()
				targetLabel.SetText(fmt.Sprintf("目标目录: %s", dir.Name()))
			}
		}, myWindow)
	})

	// 操作类型选择
	operationSelect := widget.NewSelect([]string{"copy", "rename", "prefix", "suffix"}, func(value string) {
		config.Operation = value
	})
	operationSelect.SetSelected("copy")

	// 前缀输入
	prefixEntry := widget.NewEntry()
	prefixEntry.SetPlaceHolder("输入文件名前缀")

	// 后缀输入
	suffixEntry := widget.NewEntry()
	suffixEntry.SetPlaceHolder("输入文件名后缀")

	// Worker数量
	workerEntry := widget.NewEntry()
	workerEntry.SetText("4")
	workerEntry.SetPlaceHolder("并发worker数量")

	// 选项
	recursiveCheck := widget.NewCheck("递归处理子目录", func(checked bool) {
		config.Recursive = checked
	})

	md5Check := widget.NewCheck("校验MD5", func(checked bool) {
		config.VerifyMD5 = checked
	})

	// 进度条
	progressBar := widget.NewProgressBar()
	progressBar.Hide()

	// 状态标签
	statusLabel := widget.NewLabel("就绪")
	statusLabel.Wrapping = fyne.TextWrapWord

	// 日志输出
	logText := widget.NewRichTextFromMarkdown("")
	logScroll := container.NewScroll(logText)
	logScroll.SetMinSize(fyne.NewSize(0, 150))

	// 开始按钮
	startBtn := widget.NewButton("开始处理", func() {
		// 验证配置
		if config.SourceDir == "" {
			dialog.ShowError(fmt.Errorf("请选择源目录"), myWindow)
			return
		}
		if config.TargetDir == "" {
			dialog.ShowError(fmt.Errorf("请选择目标目录"), myWindow)
			return
		}

		// 解析worker数量
		var numWorkers int
		if _, err := fmt.Sscanf(workerEntry.Text, "%d", &numWorkers); err != nil || numWorkers <= 0 {
			numWorkers = 4
		}
		config.NumWorkers = numWorkers

		// 更新前缀后缀
		config.Prefix = prefixEntry.Text
		config.Suffix = suffixEntry.Text

		// 禁用开始按钮
		startBtn.Disable()
		progressBar.Show()
		progressBar.SetValue(0)
		statusLabel.SetText("正在处理...")
		logText.ParseMarkdown("")

		// 在goroutine中执行处理
		go func() {
			proc := processor.NewProcessor(config)
			
			// 启动进度更新goroutine
			done := make(chan bool)
			go func() {
				for {
					select {
					case <-done:
						return
					default:
						current, total := proc.GetProgress()
						if total > 0 {
							progress := float64(current) / float64(total)
							progressBar.SetValue(progress)
							statusLabel.SetText(fmt.Sprintf("处理中: %d/%d (%.1f%%)", current, total, progress*100))
						}
					}
				}
			}()

			// 执行处理
			err := proc.Process()
			done <- true

			// 更新UI
			current, total := proc.GetProgress()
			progressBar.SetValue(1.0)
			
			if err != nil {
				statusLabel.SetText(fmt.Sprintf("处理完成，但有错误: %v", err))
				errors := proc.GetErrors()
				logContent := "## 错误列表:\n\n"
				for i, e := range errors {
					if i < 20 {
						logContent += fmt.Sprintf("- %v\n", e)
					}
				}
				if len(errors) > 20 {
					logContent += fmt.Sprintf("\n... 还有 %d 个错误\n", len(errors)-20)
				}
				logText.ParseMarkdown(logContent)
			} else {
				statusLabel.SetText(fmt.Sprintf("处理完成! 成功处理 %d 个文件", total))
				logText.ParseMarkdown(fmt.Sprintf("## 处理完成!\n\n成功处理 %d 个文件", total))
			}

			startBtn.Enable()
		}()
	})

	// 布局
	form := container.NewVBox(
		widget.NewCard("目录选择", "", container.NewVBox(
			sourceLabel,
			sourceBtn,
			targetLabel,
			targetBtn,
		)),
		widget.NewCard("操作设置", "", container.NewVBox(
			widget.NewForm(
				widget.NewFormItem("操作类型", operationSelect),
				widget.NewFormItem("文件名前缀", prefixEntry),
				widget.NewFormItem("文件名后缀", suffixEntry),
				widget.NewFormItem("并发Worker数", workerEntry),
			),
			recursiveCheck,
			md5Check,
		)),
		widget.NewCard("进度", "", container.NewVBox(
			progressBar,
			statusLabel,
		)),
		widget.NewCard("日志", "", logScroll),
		startBtn,
	)

	myWindow.SetContent(container.NewScroll(form))
	myWindow.ShowAndRun()
}

