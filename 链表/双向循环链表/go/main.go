package main

import (
	"fmt"
)

type node struct {
	data int
	last *node
	next *node
}

func NewNode() *node {
	head := &node{}
	head.data = 0
	head.last = head
	head.next = head
	return head
}

func(this *node) Push_back(val int) {
	p := &node{
		data: val,
		next: this,
		last: this.last,
	}

	this.last.next = p
	this.last = p

	this.data++
}

func(this *node) Push_front(val int) {
	p := &node{
		data: val,
		next: this.next,
		last: this,
	}

	this.next.last = p
	this.next = p

	this.data++
}

func(this *node) Insert(index int, val int) {
	if index < 1 || index > this.data + 1 {
		panic("out of index")
	}

	temp := this
	for i := 1; i < index; i++ {
		temp = temp.next
	}

	p := &node{
		data: val,
		next: temp.next,
		last: temp,
	}

	temp.next.last = p
	temp.next = p

	this.data++
}

func(this *node) Remove(index int) int {
	if index < 1 || index > this.data {
		panic("out of index")
	}

	temp := this
	for i := 0; i < index; i++ {
		temp = temp.next
	}

	temp.last.next = temp.next
	temp.next.last = temp.last
	this.data--

	// 这里我担心如果直接return temp.data容易导致temp逃逸到堆区上，不会被gc机制回收
	val := temp.data
	return val
}

func(this *node) Print() {
	temp := this.next
	for temp != this {
		fmt.Printf("%d ", temp.data)
		temp = temp.next
	}
	fmt.Println()
}

func main() {
	head := NewNode()

	head.Insert(1, 1)
	head.Insert(2, 2)
	head.Insert(3, 3)
	head.Insert(4, 4)
	head.Insert(5, 5)

	head.Print()

	head.Remove(2)
	head.Print()
}