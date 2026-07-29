// J. Just Half is Enough
// URL: https://codeforces.com/group/zZYq310uLQ/contest/706234/problem/J
// Time: 7/26/2026, 2:20:59 PM
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

void solve() {
    int n, m; cin >> n >> m;
    int dir = 0;
    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        if(u < v) dir++;
    }

    vi order(n);
    if (dir >= ceil(m / 2.0)) {
        for (int i = 1; i <= n; i++) {
            order[i - 1] = i;
        }
    } else {
        for (int i = 1; i <= n; i++) {
            order[n - i] = i;
        }
    }

    cout << order << "\n";
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