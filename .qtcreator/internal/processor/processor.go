package processor

import (
	"fmt"
	"os"
	"path/filepath"
	"sync"
	"sync/atomic"

	"file-processor/internal/fileops"
	"file-processor/internal/progress"
)

// Processor 文件处理器
type Processor struct {
	config   *Config
	progress *progress.Progress
	errors   []error
	mu       sync.Mutex
}

// NewProcessor 创建新的处理器
func NewProcessor(config *Config) *Processor {
	if err := config.Validate(); err != nil {
		panic(err)
	}

	return &Processor{
		config:   config,
		progress: progress.NewProgress(),
		errors:   make([]error, 0),
	}
}

// Process 执行文件处理
func (p *Processor) Process() error {
	// 确保目标目录存在
	if err := os.MkdirAll(p.config.TargetDir, 0755); err != nil {
		return fmt.Errorf("创建目标目录失败: %v", err)
	}

	// 收集文件列表
	files, err := p.collectFiles()
	if err != nil {
		return fmt.Errorf("收集文件列表失败: %v", err)
	}

	if len(files) == 0 {
		return fmt.Errorf("源目录中没有找到文件")
	}

	p.progress.SetTotal(int64(len(files)))

	// 创建任务通道和结果通道
	taskChan := make(chan *fileops.Task, p.config.NumWorkers*2)
	errorChan := make(chan error, p.config.NumWorkers)

	// 启动worker goroutines
	var wg sync.WaitGroup
	for i := 0; i < p.config.NumWorkers; i++ {
		wg.Add(1)
		go p.worker(i, taskChan, errorChan, &wg)
	}

	// 启动错误收集goroutine
	var errorWg sync.WaitGroup
	errorWg.Add(1)
	go func() {
		defer errorWg.Done()
		for err := range errorChan {
			p.mu.Lock()
			p.errors = append(p.errors, err)
			p.mu.Unlock()
		}
	}()

	// 发送任务到通道
	go func() {
		defer close(taskChan)
		for _, file := range files {
			task := &fileops.Task{
				SourcePath: file,
				TargetDir:  p.config.TargetDir,
				Operation:  p.config.Operation,
				Prefix:     p.config.Prefix,
				Suffix:     p.config.Suffix,
				VerifyMD5:  p.config.VerifyMD5,
			}
			taskChan <- task
		}
	}()

	// 等待所有worker完成
	wg.Wait()
	close(errorChan)
	errorWg.Wait()

	// 显示结果
	p.progress.Finish()
	p.showResults()

	if len(p.errors) > 0 {
		return fmt.Errorf("处理完成，但有 %d 个错误", len(p.errors))
	}

	return nil
}

// collectFiles 收集要处理的文件列表
func (p *Processor) collectFiles() ([]string, error) {
	var files []string

	walkFunc := func(path string, info os.FileInfo, err error) error {
		if err != nil {
			return err
		}
		if !info.IsDir() {
			files = append(files, path)
		}
		return nil
	}

	if p.config.Recursive {
		err := filepath.Walk(p.config.SourceDir, walkFunc)
		if err != nil {
			return nil, err
		}
	} else {
		entries, err := os.ReadDir(p.config.SourceDir)
		if err != nil {
			return nil, err
		}
		for _, entry := range entries {
			if !entry.IsDir() {
				files = append(files, filepath.Join(p.config.SourceDir, entry.Name()))
			}
		}
	}

	return files, nil
}

// worker 工作协程
func (p *Processor) worker(id int, taskChan <-chan *fileops.Task, errorChan chan<- error, wg *sync.WaitGroup) {
	defer wg.Done()

	for task := range taskChan {
		if err := fileops.ExecuteTask(task); err != nil {
			errorChan <- fmt.Errorf("文件 %s 处理失败: %v", task.SourcePath, err)
		} else {
			p.progress.Increment()
		}
	}
}

// showResults 显示处理结果
func (p *Processor) showResults() {
	fmt.Printf("\n处理完成!\n")
	fmt.Printf("总文件数: %d\n", p.progress.Total())
	fmt.Printf("成功: %d\n", p.progress.Current())
	fmt.Printf("失败: %d\n", len(p.errors))

	if len(p.errors) > 0 {
		fmt.Println("\n错误列表:")
		for i, err := range p.errors {
			if i < 10 { // 只显示前10个错误
				fmt.Printf("  - %v\n", err)
			}
		}
		if len(p.errors) > 10 {
			fmt.Printf("  ... 还有 %d 个错误\n", len(p.errors)-10)
		}
	}
}

// GetProgress 获取进度信息（用于GUI）
func (p *Processor) GetProgress() (current, total int64) {
	return p.progress.Current(), p.progress.Total()
}

// GetErrors 获取错误列表（用于GUI）
func (p *Processor) GetErrors() []error {
	p.mu.Lock()
	defer p.mu.Unlock()
	return p.errors
}























