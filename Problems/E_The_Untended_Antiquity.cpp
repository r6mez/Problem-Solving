/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// E. The Untended Antiquity
// URL: https://codeforces.com/problemset/problem/869/E
// Time: 5/30/2025, 7:16:43 PM
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

struct Fenwick2DAdd {
    int n, m;
    vector<vi> T1, T2, T3, T4;

    Fenwick2DAdd(int _n, int _m)
        : n(_n), m(_m),
        T1(n + 1, vi(m + 1)),
        T2(n + 1, vi(m + 1)),
        T3(n + 1, vi(m + 1)),
        T4(n + 1, vi(m + 1))
    {    
}

    void add(vector<vi>& t, int x, int y, int v) {
        for (int i = x; i <= n; i += i & -i)
            for (int j = y; j <= m; j += j & -j)
                t[i][j] += v;
    }

    void rangeAdd(int x, int y, int v) {
        add(T1, x, y, v);
        add(T2, x, y, v * (y - 1));
        add(T3, x, y, v * (x - 1));
        add(T4, x, y, v * (x - 1) * (y - 1));
    }

    void rangeUpdate(int x1, int y1, int x2, int y2, int val) {
        rangeAdd(x1, y1, val);
        rangeAdd(x1, y2 + 1, -val);
        rangeAdd(x2 + 1, y1, -val);
        rangeAdd(x2 + 1, y2 + 1, val);
    }

    int prefixSum(int x, int y) const {
        int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
        for (int i = x; i > 0; i -= i & -i)
            for (int j = y; j > 0; j -= j & -j) {
                s1 += T1[i][j];
                s2 += T2[i][j];
                s3 += T3[i][j];
                s4 += T4[i][j];
            }
        return s1 * x * y - s2 * x - s3 * y + s4;
    }

    int rangeQuery(int x1, int y1, int x2, int y2) const {
        return prefixSum(x2, y2)
            - prefixSum(x1 - 1, y2)
            - prefixSum(x2, y1 - 1)
            + prefixSum(x1 - 1, y1 - 1);
    }
};

void Ramez() {
    int n, m, q; cin >> n >> m >> q;

    map<array<int, 4>, int> code;
    mt19937_64 randomNumber(chrono::high_resolution_clock::now().time_since_epoch().count());

    Fenwick2DAdd t(n, m);

    while (q--) {
        int ops, x1, y1, x2, y2;
        cin >> ops >> x1 >> y1 >> x2 >> y2;
        auto key = array<int, 4>{x1, y1, x2, y2};

        if (ops == 1) {
            int w = randomNumber(); 
            code[key] = w;
            t.rangeUpdate(x1, y1, x2, y2, w);
        }
        else if (ops == 2) {
            int w = code[key];     
            t.rangeUpdate(x1, y1, x2, y2, -w);
        }
        else {
            int x = t.rangeQuery(x1, y1, x1, y1);
            int y = t.rangeQuery(x2, y2, x2, y2);
            if (x == y) cout << "Yes\n";
            else cout << "No\n";
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