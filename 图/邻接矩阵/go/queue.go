package main

import (
	"fmt"
)

type Node struct {
	data int
	next *Node
}

func NewQueue() *Node {
	return &Node{
		data: 0,
		next: nil,
	}
}

func(this *Node) GetLength() int {
	return this.data
}

func(this *Node) Empty() bool {
	if this.next == nil {
		return true
	} else {
		return false
	}
}

func(this *Node) Push_back(val int) {
	temp := this
	for(temp.next != nil) {
		temp = temp.next
	}
	temp.next = &Node{
		data: val,
		next: nil,
	}
	this.data++
}

func(this *Node) Pop_front() int {
	if this.Empty() {
		panic("out of range")
	}

	val := this.next.data // 避免内存逃逸
	this.next = this.next.next
	this.data--
	return val
}

func(this *Node) Print() {
	temp := this.next
	for temp != nil {
		fmt.Printf("%d ", temp.data)
		temp = temp.next
	}
	fmt.Println()
}