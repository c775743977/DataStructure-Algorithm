package main

import (
	"fmt"
)

func InterpolationSearch(a []int, key int) int {
	var low int = 0
	var high int = len(a) - 1

	for high >= low {
		mid := low + (high - low) * (key - a[low]) / (a[high] - a[low])
		if key > a[mid] {
			low = mid + 1
		} else if key < a[mid] {
			high = mid - 1
		} else {
			return mid
		}
	}

	return -1
}


func main() {
	arr := []int{1, 16, 24, 35, 47, 59, 62, 73, 88, 99}

	fmt.Println(InterpolationSearch(arr, 62))
}