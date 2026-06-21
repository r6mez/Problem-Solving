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
// 	s := readWord()
// 	count := 0
// 	for i := 0; i < n; i++ {
// 		b := 0; w := 0; y := 0; g := 0
// 		for j := i * 4; j < i * 4 + 4; j++ {
// 			if s[j] == 'B' { b++ }
// 			if s[j] == 'W' { w++ }
// 			if s[j] == 'Y' { y++ }
// 			if s[j] == 'G' { g++ }
// 		}

// 		if((w + b == 0) || (y + g == 0)) { count++ }
// 	}
// 	writer.WriteString(strconv.Itoa(count) + "\n")
// }

// func main(){
// 	scanner.Split(bufio.ScanWords)
// 	t := 1
// 	t = readInt()
// 	for range t {
// 		solve()
// 	}
// 	writer.Flush()
// }