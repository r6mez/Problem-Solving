// D. Points
// URL: https://codeforces.com/contest/19/problem/D
// Time: 3/8/2026, 6:44:29 AM
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
    static constexpr T unit = -1;
    T f(T a, T b) { return max(a, b); } // (any associative fn)
    vector<T> s; int n;
    SegTree(int n = 0, T def = unit) : n(n) {
        int sz = 1;
        while (sz < n) sz *= 2;
        this->n = sz;
        s.assign(2 * sz, def);
    }
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
    int upper_bound(int b, int e, T threshold) { // leftmost index in [b,e) where value > threshold
        return walk(1, 0, n, b, e, threshold);
    }
    int walk(int node, int nl, int nr, int b, int e, T threshold) {
        if (nr <= b || e <= nl || s[node] <= threshold) return -1;
        if (nr - nl == 1) return nl;
        int mid = (nl + nr) / 2;
        int left = walk(2 * node, nl, mid, b, e, threshold);
        if (left != -1) return left;
        return walk(2 * node + 1, mid, nr, b, e, threshold);
    }
};

void solve() {
    int n; cin >> n;
    vector<array<int, 3>> points(n);
    vi v;
    for (auto& [op, x, y] : points) {
        string s;
        cin >> s >> x >> y;
        if (s == "add") op = 0;
        else if (s == "remove") op = 1;
        else op = 2;
        v.push_back(x);
    }

    sort(all(v));
    v.erase(unique(all(v)), v.end());
    int cnt = v.size();

    map<int, int> rev, idx;
    for (int i = 0; i < cnt; i++) {
        rev[i] = v[i];
        idx[v[i]] = i;
    }

    vector<set<int>> ys(cnt);
    SegTree seg(cnt);

    for (auto& [op, x, y] : points) {
        int i = idx[x];
        if (op == 0) {
            ys[i].insert(y);
            seg.update(i, *ys[i].rbegin());
        }
        else if (op == 1) {
            ys[i].erase(y);
            seg.update(i, ys[i].empty() ? -1 : *ys[i].rbegin());
        }
        else {
            int start = upper_bound(all(v), x) - v.begin();
            int i = seg.upper_bound(start, cnt, y);
            if (i == -1) cout << "-1\n";
            else cout << rev[i] << " " << *ys[i].upper_bound(y) << "\n";
        }
    }
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