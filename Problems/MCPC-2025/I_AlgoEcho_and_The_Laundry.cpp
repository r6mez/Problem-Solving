// I. AlgoEcho and The Laundry
// URL: https://codeforces.com/group/Rilx5irOux/contest/636870/problem/I
// Time: 5/12/2026, 3:50:44 PM
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
    int a, b, x; cin >> a >> b >> x;
    int robes = b / x;
    int rem = (b % x);
    int count = (x + 1) * robes + (rem ? (rem + 1) : 0);
    if(count <= a) cout << "YES\n";
    else cout << "NO\n";
}

/*
- - - - 
*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}