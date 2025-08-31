/*
    One day, I'm gonna grow wings
*/
// C. Against the Difference
// URL: https://codeforces.com/contest/2136/problem/C
// Time: 8/28/2025, 6:03:02 PM
#include <bits/stdc++.h>
using namespace std;
#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { cin.tie(nullptr)->sync_with_stdio(false); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007;

struct block {
    int l, r, w;
};

void solve() {
    int n; cin >> n;
    vi a(n); cin >> a; 
    
    vector<vi> pos(n + 1);
    for (int i = 1; i <= n; ++i) {
        pos[a[i - 1]].push_back(i);
    }

    vector<block> blocks;
    for (int v = 1; v <= n; ++v) {
        for (int s = 0; s + v <= pos[v].size(); ++s) {
            blocks.push_back({  pos[v][s], pos[v][s + v - 1], v });
        }
    }

    int m = blocks.size();

    if (m == 0) {
        cout << 0 << '\n';
        return;
    }

    sort(all(blocks), [](block& x, block& y) { return x.r < y.r; });

    vi rs(m), ls(m), w(m);
    for (int i = 0; i < m; ++i) {
        w[i] = blocks[i].w; rs[i] = blocks[i].r; ls[i] = blocks[i].l;
    }

    vi dp(m, 0); dp[0] = w[0];
    for (int i = 1; i < m; ++i) {
        int j = (upper_bound(rs.begin(), rs.begin() + i, ls[i] - 1) - rs.begin()) - 1;
        dp[i] = max((j >= 0 ? dp[j] : 0) + w[i], dp[i - 1]);
    }

    cout << dp[m - 1] << '\n';
}

/*

*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}