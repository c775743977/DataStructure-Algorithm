package main

import (
	"fmt"
	"math"
)

func TriangleArea(a float64, b float64, angleInDegrees float64) float64 {
	angleInRadians := angleInDegrees * (math.Pi / 180.0)
	area := 0.5 * a * b * math.Sin(angleInRadians)
	return area
}

func main() {
	result := TriangleArea(5, 3, 90)
	fmt.Println(result)
}