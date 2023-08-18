package main

import (
	"fmt"
)

type queue struct {
	q_data []int
	q_rear int
	q_front int
}

func NewQueue(max int) *queue {
	return &queue{
		q_data: make([]int, max + 1),
		q_rear: 0,
		q_front: 0,
	}
}

func(this *queue) Empty() bool {
	if this.q_front == this.q_rear {
		return true
	} else {
		return false
	}
}

func(this *queue) Push_back(data int) {
	if (this.q_rear + 1) % len(this.q_data) == this.q_front {
		fmt.Println("out of index")
		return;
	}

	this.q_data[this.q_rear] = data
	this.q_rear = (this.q_rear + 1) % len(this.q_data)
}

func(this *queue) Pop_front() int {
	if this.Empty() {
		fmt.Println("empty queue!")
		return 0
	}

	data := this.q_data[this.q_front]
	this.q_data[this.q_front] = 0
	this.q_front = (this.q_front + 1) % len(this.q_data)
	return data
}

func(this *queue) Getlength() int {
	return (this.q_rear + len(this.q_data) - this.q_front) % len(this.q_data)
}

func main() {
	q := NewQueue(5)

	q.Push_back(1)
	q.Push_back(2)
	q.Push_back(3)
	q.Push_back(4)
	q.Push_back(5)
	fmt.Println(q.q_data)
	q.Pop_front()
	q.Push_back(6)
	fmt.Println(q.q_data)
	q.Pop_front()
	q.Pop_front()
	fmt.Println(q.q_data)
	q.Push_back(7)
	fmt.Println(q.q_data)
	fmt.Println(q.Getlength())
}