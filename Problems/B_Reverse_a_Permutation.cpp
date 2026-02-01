// B. Reverse a Permutation
// URL: https://codeforces.com/contest/2193/problem/B
// Time: 1/27/2026, 11:25:31 PM
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
    int n; cin >> n;
    vi p(n + 1);
    for (int i = 1; i <= n; i++) cin >> p[i];
    int ind = 1;
    while (ind <= n && p[ind] == n - ind + 1) ind++;
    int id = -1;

    for (int i = ind; i <= n; i++)
    {
        if (p[i] == n - ind + 1) id = i;
    }
    for (int i = 1; i < ind; i++) cout << p[i] << ' ';

    if (id != -1)
    {
        for (int i = id; i >= ind; i--) cout << p[i] << ' ';
        for (int i = id + 1; i <= n; i++) cout << p[i] << ' ';
    }
    cout << '\n';
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