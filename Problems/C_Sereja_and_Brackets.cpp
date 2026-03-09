// C. Sereja and Brackets
// URL: https://codeforces.com/contest/380/problem/C
// Time: 3/9/2026, 1:50:00 PM
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

struct node {
    int match = 0;
    int open = 0;
    int close = 0;
};

struct SegmentTree {
private:
    vector<node> seg;
    int sz;
    node skip;

    node merge(node l, node r) {
        int cancel = min(l.open, r.close);
        
        node parent = {
            match: l.match + r.match + cancel,
            open: l.open + r.open - cancel,
            close: l.close + r.close - cancel
        };
        
        return parent;
    }

    void update(int l, int r, int node_idx, int parent_idx, node val) {
        if (l == r) {
            seg[node_idx] = val;
            return;
        }

        int mid = l + r >> 1;
        if (mid < parent_idx) update(mid + 1, r, 2 * node_idx + 2, parent_idx, val);
        else update(l, mid, 2 * node_idx + 1, parent_idx, val);
        seg[node_idx] = merge(seg[2 * node_idx + 1], seg[2 * node_idx + 2]);
    }

    node query(int l, int r, int node_idx, int lx, int rx) {
        if (l > rx || r < lx) return skip;
        if (l >= lx && r <= rx) return seg[node_idx];
        int mid = l + r >> 1;
        node a = query(l, mid, 2 * node_idx + 1, lx, rx);
        node b = query(mid + 1, r, 2 * node_idx + 2, lx, rx);
        return merge(a, b);
    }

public:
    SegmentTree(int n) {
        sz = 1; while (sz <= n) sz *= 2;
        seg = vector<node>(sz * 2, skip);
    }
    
    void update(int idx, node val) {
        update(0, sz - 1, 0, idx, val);
    }
    
    int query(int l, int r) {
        return query(0, sz - 1, 0, l, r).match;
    }
};

void solve() {
    string s; cin >> s;
    int n = s.size();
    
    SegmentTree st(n);

    for (int i = 0; i < n; i++){
        node val;
        
        if(s[i] == '(') val.open = 1;
        else val.close = 1;
        
        st.update(i, val);
    }
    

    int q; cin >> q;
    while(q--){
        int l, r; cin >> l >> r; l--; r--;
        cout << st.query(l, r) * 2 << "\n";
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