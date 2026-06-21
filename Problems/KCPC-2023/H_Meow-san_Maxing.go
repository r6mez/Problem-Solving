// package main

// import (
//     "bufio"
// 	"os"
// 	"strconv"
// )

// var scanner = bufio.NewScanner(os.Stdin)
// var writer = bufio.NewWriter(os.Stdout)

// func readInt() int {
// 	scanner.Scan()
// 	val, _ := strconv.Atoi(scanner.Text())
// 	return val
// }

// func solve() {
// 	n := readInt()
// 	arr := make([]int, n)
// 	for i := range arr {
// 		arr[i] = readInt()
// 	}

// 	pre_min_arr := make([]int, n)
// 	pre_min_arr[0] = arr[0]
// 	for i := 1; i < n; i++ {
// 		pre_min_arr[i] = min(pre_min_arr[i - 1], arr[i])
// 	}

// 	answer := 0
// 	for i := n - 1; i >= 0; i-- {
// 		answer = max(answer, arr[i] - pre_min_arr[i])
// 	}
	
// 	writer.WriteString(strconv.Itoa(answer))
// }

// func main(){
// 	scanner.Split(bufio.ScanWords)
// 	t := 1
// 	// t = readInt()
// 	for range t {
// 		solve()
// 	}
// 	writer.Flush()
// }