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

func main(){
	scanner.Split(bufio.ScanWords)
	defer writer.Flush()

	t := readInt()

	for i := 0; i < t; i++ {
		solve()
	}
}


func solve(){
    n := readInt()
    s := readInt()
    x := readInt()

    a := make([]int, n)
    sum := 0
    for i := 0; i < n; i++ {
        a[i] = readInt()
        sum += a[i]
    }

    diff := s - sum
    if diff < 0 || diff%x != 0 {
        writer.WriteString("NO\n")
    } else {
        writer.WriteString("YES\n")
    }
}