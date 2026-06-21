// package main

// import (
// 	"bufio"
// 	"os"
// 	"slices"
// 	"sort"
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

// func wi(i int)    { writer.WriteString(strconv.Itoa(i)) }
// func ww(w string) { writer.WriteString(w) }

// var pals = make([]int, 0)

// func genPalidromes(n string) {
// 	if len(n) > 6 {
// 		return
// 	}

// 	if len(n) > 0 && n[0] != '0' {
// 		val, _ := strconv.Atoi(n)
// 		pals = append(pals, val)
// 	}

// 	for i := '0'; i <= '9'; i++ {
// 		genPalidromes(string(i) + n + string(i))
// 	}
// }

// func solve() {
// 	s := readInt()

// 	if(s == 1) {
// 		wi(1)
// 		return
// 	} 

// 	if (s == 1e6) {
// 		wi(999999)
// 		return
// 	}
// 	r := sort.SearchInts(pals, s)
// 	l := r - 1
// 	dis_l := s - pals[l]
// 	dis_r := pals[r] - s
// 	if dis_l <= dis_r {
// 		wi(pals[l])
// 	} else {
// 		wi(pals[r])
// 	}
// }

// func main() {
// 	scanner.Split(bufio.ScanWords)
// 	genPalidromes("")
// 	for i := '0'; i <= '9'; i++ {
// 		genPalidromes(string(i))
// 	}
// 	slices.Sort(pals)

// 	t := 1
// 	t = readInt()
// 	for range t {
// 		solve()
// 		ww("\n")
// 	}
// 	writer.Flush()
// }
