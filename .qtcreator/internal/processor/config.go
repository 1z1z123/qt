package processor

import "fmt"

// Config 处理器配置
type Config struct {
	SourceDir  string // 源目录
	TargetDir  string // 目标目录
	Operation  string // 操作类型: copy, rename, prefix, suffix
	Prefix     string // 文件名前缀
	Suffix     string // 文件名后缀
	NumWorkers int    // 并发worker数量
	Recursive  bool   // 是否递归处理子目录
	VerifyMD5  bool   // 是否校验MD5
}

// Validate 验证配置
func (c *Config) Validate() error {
	if c.SourceDir == "" {
		return fmt.Errorf("源目录不能为空")
	}
	if c.TargetDir == "" {
		return fmt.Errorf("目标目录不能为空")
	}
	if c.NumWorkers <= 0 {
		c.NumWorkers = 4
	}
	return nil
}
