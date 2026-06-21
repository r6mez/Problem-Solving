package main

import (
	"bufio"
	"os"
	"strconv"
)

var scanner = bufio.NewScanner(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)

func readInt() int {
	scanner.Scan()
	val, _ := strconv.Atoi(scanner.Text())
	return val
}

func readWord() string {
	scanner.Scan()
	val := scanner.Text()
	return val
}

func wi(i int)    { writer.WriteString(strconv.Itoa(i)) }
func ww(w string) { writer.WriteString(w) }

func solve() {
	n := readInt(); l := readInt(); r := readInt()
	if n % (l + r) >= l {
		ww("Alice")
	} else {
		ww("Bob")
	}
}

func main() {
	scanner.Split(bufio.ScanWords)
	t := 1
	t = readInt()
	for range t {
		solve()
		ww("\n")
	}
	writer.Flush()
}
