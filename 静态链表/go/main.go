package main

import (
	"fmt"
)

var (
	MAXSIZE = 100
)

type node struct {
	data int // 可以用空接口any来表示，即可储存任意类型的数据
	cur int
}

type staticLinkList struct {
	nodes []node
}

func NewStaticLinkList() *staticLinkList {
	var sll staticLinkList
	sll.nodes = make([]node, 100)
	for i := 0; i < MAXSIZE - 1; i++ {
		sll.nodes[i].cur = i + 1;
	}

	sll.nodes[MAXSIZE - 1].data = 0 // 存储长度
	sll.nodes[MAXSIZE - 1].cur = 0

	return &sll
}

func(this *staticLinkList) Insert(target_index int, val int) {
	// 可以储存数据的index范围为1<=index<=length+1
	if target_index < 1 || target_index > this.nodes[MAXSIZE - 1].data + 1{
		panic("out of index")
	}

	// 拿到第二个空节点的index
	next_emty_cur := this.nodes[this.nodes[0].cur].cur

	if this.nodes[MAXSIZE - 1].cur == 0 { // 即表为空
		this.nodes[this.nodes[0].cur].data = val
		this.nodes[this.nodes[0].cur].cur = 0
		this.nodes[MAXSIZE - 1].cur = this.nodes[0].cur
		this.nodes[MAXSIZE - 1].data++
		this.nodes[0].cur = next_emty_cur
		return
	}
	
	index := MAXSIZE - 1

	// 循环结束拿到插入位置的index
	for i := 1; i <= target_index; i++ {
		index = this.nodes[index].cur
	}
	this.nodes[this.nodes[0].cur] = this.nodes[index]
	this.nodes[index].data = val
	this.nodes[index].cur = this.nodes[0].cur
	this.nodes[0].cur = next_emty_cur
	this.nodes[MAXSIZE - 1].data++
}

func(this *staticLinkList) Print() {
	i := this.nodes[MAXSIZE - 1].cur
	for i != 0 {
		fmt.Printf("%d ", this.nodes[i].data)
		i = this.nodes[i].cur
	}
	fmt.Println()
}

func(this *staticLinkList) Remove(index int) int {
	if index < 1 || index > this.nodes[MAXSIZE - 1].data {
		panic("out of index")
	}

	empty_cur := this.nodes[0].cur // 拿到当前第一个空节点位置

	pre_index := MAXSIZE - 1
	// 循环结束拿到目标位置的上一个节点
	for i := 1; i < index; i++ {
		pre_index = this.nodes[pre_index].cur
	}
	target_index := this.nodes[pre_index].cur // 拿到目标位置
	this.nodes[pre_index].cur = this.nodes[target_index].cur
	this.nodes[target_index].cur = empty_cur
	this.nodes[0].cur = target_index
	this.nodes[MAXSIZE - 1].data--
	return this.nodes[target_index].data
}

func(this *staticLinkList) GetLen() int {
	return this.nodes[MAXSIZE - 1].data
}

func main() {
	sll := NewStaticLinkList()
	sll.Insert(1, 1)
	sll.Insert(1, 2)
	sll.Insert(1, 3)
	sll.Insert(1, 4)
	sll.Insert(1, 5)
	sll.Print()

	fmt.Println(sll.Remove(2))
	sll.Print()

	fmt.Println(sll.Remove(2))
	sll.Print()

	fmt.Println(sll.Remove(1))
	sll.Print()

	fmt.Println(sll.Remove(1))
	sll.Print()

	fmt.Println(sll.Remove(2))
	sll.Print()
}