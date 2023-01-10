package main

import "fmt"

func combinationSum3(k int, n int) [][]int {
	var ans [][]int
	var temp []int

	var solve func(int, int)
	solve = func(start int, sum int) {
		if len(temp) == k {
			if sum == n {
				ans = append(ans, append([]int{}, temp...))
			}
			return
		}

		for i := start; i <= 9; i++ {
			temp = append(temp, i)
			solve(i+1, sum+i)
			temp = temp[:len(temp)-1]
		}
	}

	solve(1, 0)

	return ans
}

func main() {
	n := 7
	k := 3

	var res [][]int
	res = combinationSum3(k, n)

	fmt.Println(res)
}
