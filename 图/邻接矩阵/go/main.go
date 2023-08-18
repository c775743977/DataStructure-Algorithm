package main

import (
	"fmt"
)

var (
	MAXVEX int = 100
	INFINITY int = 65535
)

type Graph struct {
	vexs []string
	arcs [][]int
	vexsNum int
	arcsNum int
	visited []bool
}

func NewGraph() *Graph {
	g := &Graph{
		vexs: make([]string, MAXVEX),
		visited: make([]bool, MAXVEX),
	}
	g.arcs = make([][]int, MAXVEX)
	for i := range g.arcs {
		g.arcs[i] = make([]int, MAXVEX)
	}

	for i := range g.arcs {
		for j := range g.arcs[i] {
			if i == j {
				g.arcs[i][j] = 0
			} else {
				g.arcs[i][j] = INFINITY
			}
		}
	}

	fmt.Printf("input vex num:")
	fmt.Scan(&g.vexsNum)
	fmt.Printf("input arc num:")
	fmt.Scan(&g.arcsNum)

	for i := 0; i < g.vexsNum; i++ {
		fmt.Printf("input vex%d:", i)
		fmt.Scan(&g.vexs[i])
	}

	var x,y,w int
	for i := 0; i < g.arcsNum; i++ {
		fmt.Printf("input arc%d x:", i)
		fmt.Scan(&x)
		fmt.Printf("input arc%d y:", i)
		fmt.Scan(&y)
		fmt.Printf("input arc%d w:", i)
		fmt.Scan(&w)
		g.arcs[x][y] = w
		// 无向图
		// g.arcs[y][x] = w
	}

	return g
}

func(this *Graph) Print() {
	for i := 0; i < this.vexsNum; i++ {
		fmt.Printf("%s\t", this.vexs[i])
	}
	fmt.Println()

	for i := 0; i < this.vexsNum; i++ {
		for j := 0; j < this.vexsNum; j++ {
			fmt.Printf("%d\t", this.arcs[i][j])
		}
		fmt.Println()
	}
}

func(this *Graph) DFS(index int) {
	this.visited[index] = true
	fmt.Printf("%s\t", this.vexs[index])

	for i := 0; i < this.vexsNum; i++ {
		// 无向图
		// if !this.visited[i] && this.arcs[index][i] == 1 {
		// 	this.DFS(i)
		// }
		
		// 有向图
		if !this.visited[i] && this.arcs[index][i] != INFINITY && this.arcs[index][i] != 0 {
			this.DFS(i)
		}
	}
}

func(this *Graph) DFSTraverse() {
	for i := 0; i < this.vexsNum; i++ {
		this.visited[i] = false
	}

	for i := 0; i < this.vexsNum; i++ {
		if !this.visited[i] {
			this.DFS(i)
		}
	}
}

func(this *Graph) BFSTraverse() {
	q := NewQueue()
	for i := 0; i < this.vexsNum; i++ {
		this.visited[i] = false
	}

	for i := 0; i < this.vexsNum; i++ {
		if !this.visited[i] {
			q.Push_back(i)
			fmt.Printf("%s ", this.vexs[i])
			this.visited[i] = true
		}
		for(!q.Empty()) {
			index := q.Pop_front()
			for i := 0; i < this.vexsNum; i++ {
				if !this.visited[i] && this.arcs[index][i] != 0 && this.arcs[index][i] != INFINITY {
					q.Push_back(i)
					fmt.Printf("%s ", this.vexs[i])
					this.visited[i] = true
				}
			}
		}
	}
}

func main() {
	g := NewGraph()

	g.Print()

	g.DFSTraverse()

	g.BFSTraverse()
}