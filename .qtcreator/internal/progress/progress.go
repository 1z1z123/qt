package progress

import (
	"sync/atomic"
)

// Progress 进度跟踪器
type Progress struct {
	current int64
	total   int64
}

// NewProgress 创建新的进度跟踪器
func NewProgress() *Progress {
	return &Progress{}
}

// SetTotal 设置总数
func (p *Progress) SetTotal(total int64) {
	atomic.StoreInt64(&p.total, total)
}

// Increment 增加当前进度
func (p *Progress) Increment() {
	atomic.AddInt64(&p.current, 1)
}

// Current 获取当前进度
func (p *Progress) Current() int64 {
	return atomic.LoadInt64(&p.current)
}

// Total 获取总数
func (p *Progress) Total() int64 {
	return atomic.LoadInt64(&p.total)
}

// Percentage 获取百分比
func (p *Progress) Percentage() float64 {
	total := p.Total()
	if total == 0 {
		return 0
	}
	return float64(p.Current()) / float64(total) * 100
}

// Finish 完成
func (p *Progress) Finish() {
	// 可以在这里添加完成时的处理
}
