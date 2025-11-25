fun main() {
    var t = readLine()!!.toInt()

    while (t > 0) {
        var s = readLine()!!.toCharArray()
        var cnt = 0
        var farestPlus = -1
        for(i in s.indices){
            if(s[i] == '+') farestPlus = i
        }

        var can = true
        var swap = false
        var l = -1
        var r = -1

        for (i in s.indices) {
            if(s[i] == '+') {
                cnt++
            } else {
                cnt--
            }

            
            if(cnt < 0 && swap == false){
                if(farestPlus > i){
                    val temp = s[i]
                    s[i] = s[farestPlus]
                    s[farestPlus] = temp
                    cnt = cnt + 2
                    l = i
                    r = farestPlus
                    swap = true
                } else {
                    can = false
                    break
                }
            } else if (cnt < 0 && swap == true){
                can = false
                break
            }
        }

        if(cnt < 0) can = false

        l++
        r++
        if(can){
            if(swap == false) println("1 1")
            else println("$l $r") 
        } else {
            println("-1")
        }

        t--
    }
}
