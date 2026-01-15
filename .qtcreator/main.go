package main

import (
	"flag"
	"fmt"
	"os"

	"file-processor/internal/processor"
	"file-processor/internal/ui"
)

func main() {
	// 命令行参数
	var (
		sourceDir  = flag.String("source", "", "源目录路径")
		targetDir  = flag.String("target", "", "目标目录路径")
		operation  = flag.String("op", "copy", "操作类型: copy, rename, prefix, suffix")
		prefix     = flag.String("prefix", "", "文件名前缀")
		suffix     = flag.String("suffix", "", "文件名后缀")
		numWorkers = flag.Int("workers", 4, "并发worker数量")
		recursive  = flag.Bool("recursive", false, "递归处理子目录")
		verifyMD5  = flag.Bool("md5", false, "校验MD5")
		guiMode    = flag.Bool("gui", true, "启动GUI界面")
	)
	flag.Parse()

	// 如果指定了GUI模式或没有提供命令行参数，启动GUI
	if *guiMode || (*sourceDir == "" && *targetDir == "") {
		ui.RunGUI()
		return
	}

	// 命令行模式
	if *sourceDir == "" || *targetDir == "" {
		fmt.Println("错误: 必须指定源目录和目标目录")
		fmt.Println("使用 -h 查看帮助信息")
		os.Exit(1)
	}

	// 创建处理器配置
	config := &processor.Config{
		SourceDir:  *sourceDir,
		TargetDir:  *targetDir,
		Operation:  *operation,
		Prefix:     *prefix,
		Suffix:     *suffix,
		NumWorkers: *numWorkers,
		Recursive:  *recursive,
		VerifyMD5:  *verifyMD5,
	}

	// 执行处理
	proc := processor.NewProcessor(config)
	if err := proc.Process(); err != nil {
		fmt.Printf("处理失败: %v\n", err)
		os.Exit(1)
	}

	fmt.Println("处理完成!")
}























