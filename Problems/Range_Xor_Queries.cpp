/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// Range Xor Queries
// URL: https://cses.fi/problemset/task/1650
// Time: 5/10/2025, 3:30:27 PM
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

struct SegTree {
    typedef int T;
    static constexpr T unit = 0;
    T f(T a, T b) { return a ^ b; } // (any associative fn)
    vector<T> s; int n;
    SegTree(int n = 0, T def = unit) : s(2 * n, def), n(n) {}
    void update(int pos, T val) {
        for (s[pos += n] = val; pos /= 2;)
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }
    T query(int b, int e) { // query [b, e)
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, s[b++]);
            if (e % 2) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};

void Ramez() {
    int n, q; cin >> n >> q;
    vi a(n); cin >> a;

    SegTree st(n, 0LL);

    for (int i = 0; i < n; i++){
        st.update(i, a[i]);   
    }

    while (q--) {
        int l, r; cin >> l >> r;
        cout << st.query(--l, r) << '\n';
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