/*
    One day, I'm gonna grow wings
*/
// C. MEX rose
// URL: https://codeforces.com/contest/2149/problem/C
// Time: 9/25/2025, 5:44:11 PM
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
    int n, k; cin >> n >> k;
    vi a(n); cin >> a;

    multiset<int> s(all(a));

    int cnt = 0;
    for (int i = 0; i < k; i++){
        if (!s.count(i)) cnt++;
    }

    if(s.count(k) > cnt) cnt += s.count(k) - cnt;
    cout << cnt << "\n";
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