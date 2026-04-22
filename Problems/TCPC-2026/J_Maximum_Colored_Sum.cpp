// J. Maximum Colored Sum
// URL: https://codeforces.com/group/Rilx5irOux/contest/678837/problem/J
// Time: 4/17/2026, 11:17:47 PM
#include <bits/stdc++.h>
#include <functional>
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
    int n, k, m; cin >> n >> k >> m;

    vector<vi> cats(n + 1);
    for (int i = 0; i < n; i++) {
        int p, c; cin >> p >> c;
        cats[c].push_back(p);
    }

    vi filtered;
    for (vi &arr : cats) {
        if(arr.empty()) continue;
        sort(all(arr), greater<>());
        for(int i = 0; i < m && i < arr.size(); i++){
            filtered.push_back(arr[i]);
        }
    }

    if (filtered.size() < k) finish("-1");

    sort(all(filtered), greater<>());
    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += filtered[i];
    }

    cout << sum << "\n";
}

/*

*/

signed main() {
    // UseFile();
    // FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}