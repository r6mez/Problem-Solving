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
// 	x := readInt()
// 	y := readInt()
// 	writer.WriteString(strconv.Itoa((x + y)));
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