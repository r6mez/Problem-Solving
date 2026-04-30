#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
using namespace std;

static char ibuf[1 << 16];
static int ip = 0, ilen = 0;
inline char gc() {
    if (ip == ilen) { ilen = fread(ibuf, 1, sizeof ibuf, stdin); ip = 0; }
    return ibuf[ip++];
}
inline int readInt() {
    int x = 0; char c = gc();
    while (c < '0' || c > '9') c = gc();
    while (c >= '0' && c <= '9') { x = x * 10 + (c - '0'); c = gc(); }
    return x;
}

static char obuf[1 << 16];
static int op = 0;
inline void flush() { fwrite(obuf, 1, op, stdout); op = 0; }
inline void putStr(const char* s, int len) {
    if (op + len > (int)sizeof(obuf) - 8) flush();
    memcpy(obuf + op, s, len); op += len;
}

int gcd(int a, int b) { while (b) { a %= b; int t = a; a = b; b = t; } return a; }

const int MAXV = 1e7;
static bool valid[MAXV + 1];

int main() {
    int n = readInt();
    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = readInt();

    if (n == 1) {
        int q = readInt();
        while (q--) { readInt(); putStr("YES\n", 4); }
        flush();
        return 0;
    }

    vector<int> pre(n), suf(n);
    pre[0] = a[0];
    for (int i = 1; i < n; i++) pre[i] = gcd(pre[i - 1], a[i]);
    suf[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) suf[i] = gcd(a[i], suf[i + 1]);

    set<int> gs;
    gs.insert(suf[1]);
    gs.insert(pre[n - 2]);
    for (int i = 1; i < n - 1; i++)
        gs.insert(gcd(pre[i - 1], suf[i + 1]));

    memset(valid, 0, sizeof valid);
    for (int g : gs) {
        for (int d = 1; (long long)d * d <= g; d++) {
            if (g % d == 0) {
                valid[d] = true;
                valid[g / d] = true;
            }
        }
    }

    int q = readInt();
    while (q--) {
        int k = readInt();
        bool ans = (k <= MAXV) && valid[k];
        if (ans) putStr("YES\n", 4);
        else putStr("NO\n", 3);
    }
    flush();
    return 0;
}