// A. Greater Than XOR
// URL: https://codeforces.com/group/Rilx5irOux/contest/686782/problem/A
// Time: 5/25/2026, 2:23:28 PM
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
    int n;
    cin>> n;
    int ans = -1;
    vi a(n);
    cin >> a;
    vi xorr(n+1);
    vi sum(n+1);
    for(int i = 0 ; i < n ; ++i )
    {
        xorr[i+1] = xorr[i] ^ a[i];
        sum[i+1] = sum[i] + a[i];
    
    }
    int prev = 0;
    for(int i = 1 ; i <= n ; ++i )
    {
            if((xorr[i] ^ xorr[prev]) < (sum[i] - sum[prev]))
            {
                ans++   ;
                prev = i ;
            }
        }
        if(ans == -1) cout << -1 << "\n";
        else
    cout << ans +1<< "\n";
}


signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}