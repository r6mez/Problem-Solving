// B. Anne and Gilbert at Pont des Arts
// URL: https://nucpa.contest.codeforces.com/group/jiO369yEKE/contest/671480/problem/B
// Time: 2/14/2026, 8:37:15 PM
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
    int l, r; cin >> l >> r;
    
    int cnt = 0;
    if(l <= 18 && 18 <= r) 
        cnt+=1;
    
    cout << cnt << "\n";
}

/*
w h
w != h
l <= w*2 + h*2 = w * h <= r
2 (w + h) = w * h

4 * 4 = 16
3 * 6 = 18
6 * 3 = 18


*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}