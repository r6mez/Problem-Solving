/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// D. Iahub and Xors
// URL: https://codeforces.com/problemset/problem/341/D
// Time: 5/30/2025, 6:34:54 PM
#include <bits/stdc++.h>
using namespace std;
#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007;

struct Fenwick2DXOR {
    int n, m;
    vector<vi> bit[2][2];

    Fenwick2DXOR(int _n, int _m) : n(_n), m(_m) {
        for (int px = 0; px < 2; ++px)
            for (int py = 0; py < 2; ++py)
                bit[px][py].assign(n+2, vi(m+2, 0));
    }

    void pointXOR(int x, int y, int v) {
        for (int i = x; i <= n; i += i & -i)
            for (int j = y; j <= m; j += j & -j)
                bit[x&1][y&1][i][j] ^= v;
    }

    void rangeXOR(int x1, int y1, int x2, int y2, int v) {
        if (x1 > x2 || y1 > y2) return;
        auto upd = [&](int x, int y){ if (x > 0 && y > 0) pointXOR(x, y, v); };
        upd(x1,      y1);
        upd(x2 + 1,  y1);
        upd(x1,      y2 + 1);
        upd(x2 + 1,  y2 + 1);
    }

    int prefixXOR(int x, int y) {
        if (x <= 0 || y <= 0) return 0;
        int res = 0;
        int px = x & 1, py = y & 1;
        for (int i = x; i > 0; i -= i & -i)
            for (int j = y; j > 0; j -= j & -j)
                res ^= bit[px][py][i][j];
        return res;
    }

    int rangeQuery(int x1, int y1, int x2, int y2) {
        int res = 0;
        res ^= prefixXOR(x2,   y2);
        res ^= prefixXOR(x1-1, y2);
        res ^= prefixXOR(x2,   y1-1);
        res ^= prefixXOR(x1-1, y1-1);
        return res;
    }
};

void Ramez() {
    int n, m; cin >> n >> m;

    Fenwick2DXOR t(n, n);

    while (m--) {
        int ty, x1, y1, x2, y2; cin >> ty;
        if (ty == 2) {
            int val;
            cin >> x1 >> y1 >> x2 >> y2 >> val;
            t.rangeXOR(x1, y1, x2, y2, val);
        }
        else {
            cin >> x1 >> y1 >> x2 >> y2;
            cout << t.rangeQuery(x1, y1, x2, y2) << '\n';

        }
    }
}

/*
NOTES:

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}