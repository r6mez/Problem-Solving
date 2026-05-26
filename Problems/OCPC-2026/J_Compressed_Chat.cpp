// J. Compressed Chat
// URL: https://codeforces.com/group/Rilx5irOux/contest/686782/problem/J
// Time: 5/25/2026, 2:16:56 PM
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
    string a ,b  ,c ;
    cin >> a >> b ;
    for(int i = 0 ; i < a.length() -1 ; ++i )
    {
        if(a[i] != a[i+1])
        {
            c += a[i] ;
        }
    }
    c+= a.back() ;
    if(c == b )
    {
        cout << "YES\n" ;
    }
    else
    {
        cout << "NO\n" ;
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