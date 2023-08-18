package main

import (
	"fmt"
)

func BinarySearch(arr []int, key int) int {
	var low int = 0
	var high int = len(arr) - 1
	var mid int
	for high >= low {
		mid = (high + low) / 2
		if key > arr[mid] {
			low = mid + 1
		} else if key < arr[mid] {
			high = mid - 1
		} else {
			return mid
		}
	}

	return -1
}

func main() {
	arr := []int{1, 16, 24, 35, 47, 59, 62, 73, 88, 99}
	fmt.Println(BinarySearch(arr, 16))
}