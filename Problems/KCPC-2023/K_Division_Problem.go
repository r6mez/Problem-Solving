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
// 	total := 1
// 	count := 1
// 	for n > 1 {
// 		n /= 2
// 		count *= 2
// 		total += count
// 	}
// 	writer.WriteString(strconv.Itoa(total))
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