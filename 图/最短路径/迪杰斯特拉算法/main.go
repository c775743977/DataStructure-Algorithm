package main

import (
	"fmt"
)

var INFINITY = 65535

type Graph struct {
	Vexs []byte
	Arcs [][]int
	Indexs []int // 到各点的最短路径
	Paths []int // 到各点的最短距离
}

func NewGraph(vexs []byte, arcs[][]int) *Graph {
	return &Graph{
		Vexs: vexs,
		Arcs: arcs,
		Indexs: make([]int, len(vexs)),
		Paths: make([]int, len(vexs)),
	}
}

func(this *Graph) Dijkstra() {
	// 标记最短路径是否存在
	visited := make([]bool, len(this.Vexs))

	index := 0

	// 初始化数据
	for i := 0; i < len(this.Vexs); i++ {
		visited[i] = false
		this.Indexs[i] = -1
		this.Paths[i] = this.Arcs[0][i] // 第一个顶点到其他顶点的路径
	}

	visited[0] = true // 第一个顶点到自己

	for i := 1; i < len(this.Vexs); i++ {
		min := INFINITY // 储存最短路径
		for j := 0; j < len(this.Vexs); j++ {
			if !visited[j] && this.Paths[j] < min {
				index = j
				min = this.Paths[j]
			}
		}

		visited[index] = true
		for k := 0; k < len(this.Vexs); k++ {
			// 判断是否有更新的最短路径
			if !visited[k] && min + this.Arcs[index][k] < this.Paths[k] {
				this.Paths[k] = min + this.Arcs[index][k]
				this.Indexs[k] = index
			}
		}
	}
}

func(this *Graph) PathTo(index int) {
	fmt.Printf("name:%s To name:%s shortest path is %d\n", string(this.Vexs[0]), string(this.Vexs[index]), this.Paths[index])
}

func main() {
	g := NewGraph([]byte{'A','B','C','D','E','F','G'}, [][]int{{0,10,7,INFINITY,5,INFINITY,INFINITY}, {10,0,INFINITY,6,INFINITY,INFINITY,INFINITY},{7,INFINITY,0,5,1,3,4},{INFINITY,6,5,0,INFINITY,INFINITY,2},{5,INFINITY,1,INFINITY,0,8,INFINITY},{INFINITY,INFINITY,3,INFINITY,8,0,9},{INFINITY,INFINITY,4,2,INFINITY,9,0}})
	g.Dijkstra()
	for i := 1; i < 7; i++ {
		g.PathTo(i)
	}
}
