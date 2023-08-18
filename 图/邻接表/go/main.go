package main

import (
	"fmt"
)

var MAXSIZE int = 100

type Arc struct {
	index int
	weight int
	next *Arc
}

type Vex struct {
	data string
	firstarc *Arc
}

type Graph struct {
	vexs []Vex
	visited []bool
	numVex int
	numArc int
}

func NewGraph() *Graph {
	g := &Graph{}
	fmt.Printf("input vex num:")
	fmt.Scan(&g.numVex)
	fmt.Printf("input arc num:")
	fmt.Scan(&g.numArc)
	g.vexs = make([]Vex, MAXSIZE)
	g.visited = make([]bool, MAXSIZE)
	for i := 0; i < g.numVex; i++ {
		fmt.Printf("input vex%d:", i)
		fmt.Scan(&g.vexs[i].data)
		g.vexs[i].firstarc = nil
	}

	var x, y, w int
	for i := 0; i < g.numArc; i++ {
		fmt.Printf("input x:")
		fmt.Scan(&x)
		fmt.Printf("input y:")
		fmt.Scan(&y)
		fmt.Printf("input w")
		fmt.Scan(&w)
		arc1 := &Arc{
			index: y,
			weight: w,
			next: g.vexs[x].firstarc,
		}
		g.vexs[x].firstarc = arc1
		
		// 无向图

		arc2 := &Arc{
			index: x,
			weight: w,
			next: g.vexs[y].firstarc,
		}
		g.vexs[y].firstarc = arc2
	}

	return g
}

func(this *Graph) Print() {
	for i := 0; i < this.numVex; i++ {
		fmt.Printf("%s ", this.vexs[i].data)
		arc := this.vexs[i].firstarc
		for arc != nil {
			fmt.Printf("index:%d\tweight:%d\t", arc.index, arc.weight)
			arc = arc.next
		}
		fmt.Println()
	}
}

func(this *Graph) DFS(index int) {
	this.visited[index] = true
	fmt.Printf("%s ", this.vexs[index].data)

	arc := this.vexs[index].firstarc
	for arc != nil {
		if !this.visited[arc.index] {
			this.DFS(arc.index)
		}
	}
}

func(this *Graph) DFSTraverse() {
	for i := 0; i < this.numVex; i++ {
		this.visited[i] = false
	}

	for i := 0; i < this.numVex; i++ {
		if !this.visited[i] {
			this.DFS(i)
		}
	}
}

func(this *Graph) BFSTraverse() {
	for i := 0; i < this.numVex; i++ {
		this.visited[i] = false
	}

	q := NewQueue()

	for i := 0; i < this.numVex; i++ {
		q.Push_back(i)
		fmt.Printf("%s ", this.vexs[i].data)
		this.visited[i] = true
		for !q.Empty() {
			index := q.Pop_front()
			arc := this.vexs[index].firstarc
			for arc != nil && !this.visited[arc.index] {
				q.Push_back(arc.index)
				fmt.Printf("%s ", this.vexs[arc.index].data)
				this.visited[arc.index] = true
				arc = arc.next
			}
		}
	}
}

func main() {
	
}