package main

import (
	"fmt"
)

type Node struct {
	data any
	next *Node
}

type Head struct {
	length int
	next *Node
}

func NewLinkHead() *Head {
	return &Head{
		length: 0,
		next: nil,
	}
}

func(this *Head) Push_back(content any) {
	p := new(Node)
	p.data = content
	p.next = nil
	if this.next == nil {
		this.next = p
		this.length++
		return
	}

	q := this.next
	for(q.next != nil) {
		q = q.next
	}
	q.next = p
	this.length++
}


// 我无法确定go的gc机制是否会自动回收这个被丢弃的节点，因为在c++中这个节点是手动释放的
func(this *Head) Remove(index int) {
	p := this.next
	if index == 0 {
		this.next = this.next.next
		this.length--
		return
	}

	var q *Node
	for i := 0; i < index; i++ {
		q = p
		p = p.next
	}
	q.next = p.next
	this.length--
}

func(this *Head) Print() {
	if this.next == nil {
		fmt.Println("empty link!")
		return
	}

	fmt.Println("data num:", this.length)
	p := this.next
	for(p != nil) {
		fmt.Printf("%v\t", p.data)
		p = p.next
	}
	fmt.Println()
}

func(this *Head) Clear() {
	p := this.next
	for(p != nil) {
		this.next = this.next.next
		p = nil // 尝试模拟delete操作
		p = this.next
	}
}

func main() {
	head := NewLinkHead()
	head.Push_back(1)
	head.Push_back(2)
	head.Push_back(3)
	head.Push_back(4)
	head.Push_back(5)
	head.Print()

	head.Remove(1)
	head.Print()
}