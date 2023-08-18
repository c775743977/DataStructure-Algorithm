package main

import (
	"fmt"
)
// 以下仅针对于构建自定义数组
// golang相比c++不足的在于他不能重载运算符[]，程序员对于数组底层的内存管理权限不够
// golang只能大致模拟数组的结构，不如c++那么贴近
// golang可以使用空接口代替c++中的模板，但是不如模板的使用灵活
type array struct {
	data []any
	length int
	maxsize int
}

// 这里就相当于c++的构造函数, c++在new时会执行构造函数，可以传入参数来初始化数据
// 而golang的new就没有构造函数，其实 ptr := new(t)就等价于 var t T; ptr := &t, 所以无法传参的特性让大家更喜欢自定义函数来构造实例
func NewArray(cap int) *array {
	return &array{
		data: make([]any, cap),
		length: 0,
		maxsize: cap,
	}
}

// 扩容机制等有待实现

func(this *array) Insert(pos int, data any) {
	if (this.length == this.maxsize) {
		panic("out of index")
	}

	if (pos < 0 || pos > this.length) {
		panic("out of index")
	}

	for i := this.length; i > pos; i-- {
		this.data[i] = this.data[i - 1]
	}

	this.data[pos] = data
	this.length++
}

func(this *array) Remove(pos int) any {
	if (this.length == 0 || pos < 0 || pos > this.length - 1) {
		panic("out of index")
	}

	if (pos == this.length - 1) {
		this.length--
		return this.data[pos]
	}

	var data  = this.data[pos]

	for i := pos; i < this.length - 1; i++ {
		this.data[i] = this.data[i + 1]
	}

	this.length--

	return data
}

func(this *array) Get(index int) any {
	return this.data[index]
}

func(this *array) PrintArr() {
	for i := 0; i < this.length; i++ {
		fmt.Printf("%v ", this.data[i])
	}
	fmt.Println()
}

func main() {
	my_arr := NewArray(20)

	my_arr.Insert(my_arr.length, 1)
	my_arr.Insert(my_arr.length, 2)
	my_arr.Insert(my_arr.length, 3)
	my_arr.Insert(my_arr.length, 4)
	my_arr.Insert(my_arr.length, 5)
	my_arr.Insert(my_arr.length, 6)

	my_arr.PrintArr()

	my_arr.Remove(3)

	my_arr.PrintArr()
}