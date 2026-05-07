// N. Geo!Geo!Geo!!!
// URL: https://codeforces.com/group/Rilx5irOux/contest/636158/problem/N
// Time: 5/4/2026, 3:06:13 PM
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

bool isTringle(int a, int b, int c){
    // a + b + c - max
    // max
    // a + b + c - max < max
    // a + b + c < 2 * m
    if(a + b + c < 2 * max({a, b, c})) return false;
    else return true;
}

void solve() {
    int a, x; cin >> a >> x;
    int b, y; cin >> b >> y;

    int j = 90 - x; 
    int k = 180 - y - (a == 2 ? x : j ); 
    
    if(x <= 0 || j <= 0 || y <= 0 || k <= 0){
        cout << "-1\n";
        return;
    }
    
    if(a == 1) cout << x << " " << j << " "; 
    else cout << j << " "<< x << " "; 
    
    if(b == 3) cout << y << " " << k;
    else cout << k << " " << y ; 
    
    cout << "\n";
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