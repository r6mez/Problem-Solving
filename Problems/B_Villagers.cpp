/*
    One day, I'm gonna grow wings
*/
// B. Villagers
// URL: https://codeforces.com/contest/2133/problem/B
// Time: 8/25/2025, 9:39:45 AM
#include <bits/stdc++.h>
using namespace std;
#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> auto& operator<<(auto& o, vector<T>& v) { for (auto& e : v) o << e << ' '; return o; }
template<typename T> auto& operator>>(auto& i, vector<T>& v) { for (auto& e : v) i >> e; return i; }
void FastIO() { cin.tie(nullptr)->sync_with_stdio(false); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007;

void solve() {
    int n; cin >> n;
    vi a(n); cin >> a;
    sort(all(a), greater<int>());
    // cout << a << "\n";
    int cnt = 0;
    for (int i = 0; i < n; i+=2){
        cnt += a[i];
    }
    cout << cnt << "\n";
}

/*
each time select two i, j
cnt += max(gi, gj)
gi, gj -= min(gi, gj)

6
9 5 4 3 1 1
0 5 0 3 0 1
*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}