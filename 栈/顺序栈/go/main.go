package main

import (
	"fmt"
)

type stack struct {
	data []any
	max int
	top int
}

func NewStack(maxsize int) *stack {
	return &stack{
		data: make([]any, maxsize),
		max: maxsize,
		top: 0,
	}
}

func(this *stack) Push(value any) {
	if this.top >= this.max {
		panic("out of index")
	}

	this.data[this.top] = value
	this.top++
}

func(this *stack) Pop() any {
	if this.top == 0 {
		panic("out of index")
	}

	this.top--
	return this.data[this.top]
}

func(this *stack) GetLength() int {
	return this.top
}

func(this *stack) GetTop() any {
	return this.data[this.top - 1]
}

func(this *stack) Empty() bool {
	if this.top == 0 {
		return true
	} else {
		return false
	}
}

func(this *stack) Print() {
	for i := 0; i < this.top; i++ {
		fmt.Printf("%v ", this.data[i])
	}
	fmt.Println()
}

func(this *stack) Clear() {
	this.top = 0
}

func main() {
	stack := NewStack(100)

	fmt.Println(stack.Empty())

	for i := 0; i < 10; i++ {
		stack.Push(i)
	}

	fmt.Println(stack.Empty())
	fmt.Println(stack.GetLength())
	stack.Print()
	stack.Pop()
	stack.Print()
	stack.Clear()
	fmt.Println(stack.Empty())
}