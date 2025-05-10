/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// Static Range Sum Queries
// URL: https://cses.fi/problemset/task/1646
// Time: 5/10/2025, 1:11:06 PM
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

struct SparceTable {
    int n;
    vi a;
    vector<vi> t;

    SparceTable(int n, vi a) : n(n), a(a) {
        build();
    }

    int merge(int a, int b) {
        return a + b; // You can customize this
    }

    void build() {
        int logn = 0;
        while ((1 << logn) <= n) logn++;
        t = vector<vi>(n, vi(logn));

        for (int i = 0; i < n; i++) {
            t[i][0] = a[i];
        }

        for (int pw = 1; (1 << pw) <= n; pw++) {
            for (int i = 0; i + (1 << pw) <= n; i++) {
                t[i][pw] = merge(t[i][pw - 1], t[i + (1 << (pw - 1))][pw - 1]);
            }
        }
    }

    int query(int l, int r) {
        int ret = 0;
        for (int i = 21; i >= 0; i--) {
            if ((r - l + 1) >= (1 << i)) {
                ret = merge(ret, t[l][i]);
                l += (1 << i);
            }
        }
        return ret;
    }
};

void Ramez() {
    int n, q; cin >> n >> q;
    vi a(n); cin >> a;

    SparceTable st(n, a);

    while (q--) {
        int l, r; cin >> l >> r;
        cout << st.query(--l, --r) << '\n';
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