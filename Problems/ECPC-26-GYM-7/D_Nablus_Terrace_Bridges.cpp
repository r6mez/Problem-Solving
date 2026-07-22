// D. Nablus Terrace Bridges
// URL: https://codeforces.com/group/zZYq310uLQ/contest/703989/problem/D
// Time: 7/22/2026, 2:08:35 PM
#include <bits/stdc++.h>
using namespace std;
#define int         long long
#define vi          vector<int>
#define pii         pair<int, int>
#define all(v)      v.begin(), v.end()
#define finish(s)   { cout << s << "\n"; return; }
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { cin.tie(nullptr)->sync_with_stdio(false); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007, INF = 2e18;

struct SegTree {
    typedef int T;
    static constexpr T unit = 0;
    T f(T a, T b) { return max(a, b); } // (any associative fn)
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

void solve() {
    int n; cin >> n;
    vi a(n); cin >> a;

    SegTree st(n);
    for (int i = 0; i < n; i++) {
        st.update(i, a[i]);
    }

    map<int, int> freq;

    int sum = 0;
    for(int i = 0; i < n; i++) {
        if(!freq.contains(a[i])) {
            freq[a[i]] = i;
            continue;
        }

        int j = freq[a[i]];
        if (st.query(j, i) == a[i]) {
            sum += i - j - 1;
        }

        freq[a[i]] = i;
    }

    cout << sum << "\n";
}

/*

*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) solve();
}