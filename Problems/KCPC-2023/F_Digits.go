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

// func readWord() string {
// 	scanner.Scan()
// 	val := scanner.Text()
// 	return val
// }



// func solve() {
// 	n := readInt()
// 	x := ""
// 	for n > 0 {
// 		if n < 10 {
// 			x = strconv.Itoa(n) + x
// 			break
// 		} else {
// 			x += "9"
// 			n -= 9
// 		}
// 	}
// 	writer.WriteString(x)
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