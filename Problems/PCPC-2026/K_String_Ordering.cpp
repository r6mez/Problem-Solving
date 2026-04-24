// K. String Ordering
// URL: https://codeforces.com/group/Rilx5irOux/contest/640620/problem/K
// Time: 4/24/2026, 7:49:11 PM
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
    string s; cin >> s;
    vector<string> subs(m); cin >> subs;

    sort(all(subs));
    do {
        int p = 0;
        bool ok = true;
        for (int i = 0; i < m && ok; i++) {
            int pos = s.find(subs[i], p);
            if (pos == string::npos) ok = false;
            else p = pos + subs[i].size();
        }
        if (ok) finish("YES");
    } while (next_permutation(all(subs)));
    finish("NO");
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