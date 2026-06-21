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
// 	writer.WriteString(strconv.Itoa((n + 10)));
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