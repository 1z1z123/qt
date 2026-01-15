package fileops

import (
	"crypto/md5"
	"fmt"
	"io"
	"os"
	"path/filepath"
	"strings"
)

// ExecuteTask 执行文件处理任务
func ExecuteTask(task *Task) error {
	// 读取源文件
	sourceFile, err := os.Open(task.SourcePath)
	if err != nil {
		return fmt.Errorf("打开源文件失败: %v", err)
	}
	defer sourceFile.Close()

	// 计算源文件MD5（如果需要）
	var sourceMD5 []byte
	if task.VerifyMD5 {
		hash := md5.New()
		if _, err := io.Copy(hash, sourceFile); err != nil {
			return fmt.Errorf("计算源文件MD5失败: %v", err)
		}
		sourceMD5 = hash.Sum(nil)
		sourceFile.Seek(0, 0) // 重置文件指针
	}

	// 生成目标文件名
	targetFileName := filepath.Base(task.SourcePath)
	targetFileName = applyOperation(targetFileName, task.Operation, task.Prefix, task.Suffix)
	targetPath := filepath.Join(task.TargetDir, targetFileName)

	// 确保目标目录存在
	if err := os.MkdirAll(filepath.Dir(targetPath), 0755); err != nil {
		return fmt.Errorf("创建目标目录失败: %v", err)
	}

	// 执行操作
	switch task.Operation {
	case "copy":
		return copyFile(sourceFile, targetPath, sourceMD5, task.VerifyMD5)
	case "rename":
		// 重命名实际上是复制到新位置
		return copyFile(sourceFile, targetPath, sourceMD5, task.VerifyMD5)
	case "prefix", "suffix":
		return copyFile(sourceFile, targetPath, sourceMD5, task.VerifyMD5)
	default:
		return fmt.Errorf("不支持的操作类型: %s", task.Operation)
	}
}

// applyOperation 应用操作到文件名
func applyOperation(fileName, operation, prefix, suffix string) string {
	ext := filepath.Ext(fileName)
	name := strings.TrimSuffix(fileName, ext)

	switch operation {
	case "prefix":
		if prefix != "" {
			name = prefix + name
		}
	case "suffix":
		if suffix != "" {
			name = name + suffix
		}
	case "rename":
		// 如果提供了prefix或suffix，使用它们作为新名称
		if prefix != "" {
			name = prefix
		} else if suffix != "" {
			name = suffix
		}
	}

	return name + ext
}

// copyFile 复制文件
func copyFile(source *os.File, targetPath string, sourceMD5 []byte, verifyMD5 bool) error {
	// 创建目标文件
	targetFile, err := os.Create(targetPath)
	if err != nil {
		return fmt.Errorf("创建目标文件失败: %v", err)
	}
	defer targetFile.Close()

	// 复制文件内容
	if _, err := io.Copy(targetFile, source); err != nil {
		return fmt.Errorf("复制文件内容失败: %v", err)
	}

	// 校验MD5
	if verifyMD5 && sourceMD5 != nil {
		targetFile.Seek(0, 0)
		hash := md5.New()
		if _, err := io.Copy(hash, targetFile); err != nil {
			return fmt.Errorf("计算目标文件MD5失败: %v", err)
		}
		targetMD5 := hash.Sum(nil)

		// 比较MD5
		if !equalMD5(sourceMD5, targetMD5) {
			return fmt.Errorf("MD5校验失败: 源文件与目标文件不一致")
		}
	}

	return nil
}

// equalMD5 比较两个MD5值
func equalMD5(a, b []byte) bool {
	if len(a) != len(b) {
		return false
	}
	for i := range a {
		if a[i] != b[i] {
			return false
		}
	}
	return true
}























