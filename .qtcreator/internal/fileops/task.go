package fileops

// Task 文件处理任务
type Task struct {
	SourcePath string // 源文件路径
	TargetDir  string // 目标目录
	Operation  string // 操作类型
	Prefix     string // 文件名前缀
	Suffix     string // 文件名后缀
	VerifyMD5  bool   // 是否校验MD5
}






















