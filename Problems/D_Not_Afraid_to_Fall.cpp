// D. Not Afraid to Fall
// URL: https://codeforces.com/group/zZYq310uLQ/contest/700325/problem/D
// Time: 7/19/2026, 8:06:39 PM
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
    vi a(n); cin >> a;
    vi idk(m + 4); 
    for(int x : a) idk[x] += x;

    for(int i = m; i >= 0; i--){
        idk[i] += idk[i + 1];
    }

    for(int i = 1; i <= m; i++){
        cout << idk[i] << " ";
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