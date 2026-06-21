// package main

// import (
// 	"bufio"
// 	"os"
// 	"slices"
// 	"strconv"
// 	"sort"
// )

// var scanner = bufio.NewScanner(os.Stdin)
// var writer = bufio.NewWriter(os.Stdout)

// func readInt() int {
// 	scanner.Scan()
// 	val, _ := strconv.Atoi(scanner.Text())
// 	return val
// }

// func readWord() string {
// 	scanner.Scan()
// 	val := scanner.Text()
// 	return val
// }

// func solve() {
// 	n := readInt(); m:= readInt()
// 	arr := make([]int, n + 1)
// 	for i := 1; i <= n; i++ {
// 		arr[i] = readInt()
// 	}

// 	slices.Sort(arr)
	
// 	answer := 0
// 	for range m {
// 		l := readInt(); r := readInt()
// 		count := sort.SearchInts(arr, r+1) - sort.SearchInts(arr, l)
// 		answer = max(answer, count)
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