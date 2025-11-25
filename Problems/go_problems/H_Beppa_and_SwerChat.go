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

    a := make([]int, n)
    for i := 0; i < n; i++ {
        a[i] = readInt()
    }

    b := make([]int, n)
    for i := 0; i < n; i++ {
        b[i] = readInt()
    }

    p := n - 1
    cnt := 0
    for o := n - 1; o >= 0; o-- {
        for p >= 0 && a[p] != b[o] {
            p--
            cnt++
        }
        p--
    }

    writer.WriteString(strconv.Itoa(cnt) + "\n")
}