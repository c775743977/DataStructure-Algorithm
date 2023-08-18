package main

import (
	"fmt"
)

// go需要自己实现一个队列容器，我直接用链队列，不用考虑扩容问题
type Queue struct {
	data *Node
	next *Queue
}

func NewQueue() *Queue {
	return &Queue{
		data: nil,
		next: nil,
	}
}

func(this *Queue) Push(node *Node) {
	if this.data == nil {
		this.data = node
		return
	}

	temp := this
	for temp.next != nil {
		temp = temp.next
	}
	temp.next = &Queue{
		data: node,
		next: nil,
	}
}

func(this *Queue) Pop() *Node {
	if this.data == nil {
		return nil
	}

	if this.next == nil {
		node := this.data
		this.data = nil
		return node
	}

	node := this.data
	this.data = this.next.data
	this.next = this.next.next
	return node
}

func(this *Queue) Empty() bool {
	if this.data == nil {
		return true
	} else {
		return false
	}
}

type Node struct {
	data string
	lchild *Node
	rchild *Node
}

// 因为go不存在真正意义上的引用传递，所有都是值传递，所以必须使用返回值赋值的方式来初始化
func InitTree(...*Node) *Node {
	var r_data string
	fmt.Printf("input root data:")
	fmt.Scan(&r_data)
	if r_data == "0" {
		return nil
	}
	root := &Node{
		data: r_data,
		lchild: nil,
		rchild: nil,
	}
	fmt.Println(root.data, "lchild")
	root.lchild = InitTree(root.lchild)
	fmt.Println(root.data, "rchild")
	root.rchild = InitTree(root.rchild)

	return root
}

func(this *Node) PreOrder(root *Node) {
	if root == nil {
		return
	}

	fmt.Printf("%s ", root.data)
	this.PreOrder(root.lchild)
	this.PreOrder(root.rchild)
}

func(this* Node) MidOrder(root *Node) {
	if root == nil {
		return
	}

	this.MidOrder(root.lchild)
	fmt.Printf("%s ", root.data)
	this.MidOrder(root.rchild)
}

func(this *Node) PostOrder(root *Node) {
	if root == nil {
		return
	}

	this.PostOrder(root.lchild)
	this.PostOrder(root.rchild)
	fmt.Printf("%s ", root.data)
}

func(this *Node) LevelOrder(root *Node) {
	queue := NewQueue()
	queue.Push(root)
	for !queue.Empty() {
		node := queue.Pop()
		fmt.Printf("%s ", node.data)
		if node.lchild != nil {
			queue.Push(node.lchild)
		}
		if node.rchild != nil {
			queue.Push(node.rchild)
		}
	}
}

func main() {
	tree := InitTree()
	
	tree.PreOrder(tree)
	fmt.Println()
	tree.MidOrder(tree)
	fmt.Println()
	tree.PostOrder(tree)
	fmt.Println()
	tree.LevelOrder(tree)
}