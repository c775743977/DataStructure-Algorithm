package main

import (
	"fmt"
	"strconv"
)

// 顺序栈简单实现
type stack struct {
	data []any
	top int64
}

func NewStack(maxsize int64) *stack {
	return &stack{
		data: make([]any, maxsize),
		top: 0,
	}
}

func(this *stack) Empty() bool {
	if this.top == 0 {
		return true
	} else {
		return false
	}
}

func(this *stack) Pop() any {
	this.top -= 1
	return this.data[this.top]
}

func(this *stack) Top() any {
	return this.data[this.top - 1]
}

func(this *stack) Push(data any) {
	this.data[this.top] = data
	this.top += 1
}

func GetPriority(c rune) int64 {
	if c == '+' || c == '-' {
		return 1
	} else if c == '*' || c == '/' {
		return 2
	} else if c == '(' {
		return 3
	} else {
		return 0
	}
}

func To_postfix(exp string) string {
	var str string
	my_stack := NewStack(100)
	for _, k := range exp {
		if k < '0' {
			if my_stack.Empty() || my_stack.Top() == '(' || GetPriority(k) > GetPriority(my_stack.Top().(rune)) {
				my_stack.Push(k)
				str += " "
			} else {
				for(!my_stack.Empty() && my_stack.Top() != '(') {
					str += string(my_stack.Pop().(rune))
				}
				if k == ')' {
					my_stack.Pop()
				} else {
					my_stack.Push(k)
				}
			}
		} else {
			str += string(k)
		}
	}
	for(!my_stack.Empty()) {
		str += string(my_stack.Pop().(rune))
	}
	return str
}

func Calculate(postfix string) int64 {
	my_stack := NewStack(100)
	var str string
	for _, k := range postfix {
		if k <= '9' && k >= '0' {
			str += string(k)
		} else {
			if str != "" {
				num, _ := strconv.ParseInt(str, 10, 64)
				my_stack.Push(num)
				str = ""
			}

			if k != ' ' {
				num1 := my_stack.Pop()
				num2 := my_stack.Pop()

				switch k {
				case '+':
					my_stack.Push(num2.(int64) + num1.(int64))
				case '-':
					my_stack.Push(num2.(int64) - num1.(int64))
				case '*':
					my_stack.Push(num2.(int64) * num1.(int64))
				case '/':
					my_stack.Push(num2.(int64) / num1.(int64))
				}
			}
		}
	}

	return my_stack.Pop().(int64)
}

func main() {
	fmt.Println(Calculate(To_postfix("9+(3-1)*3+10/2")))
}