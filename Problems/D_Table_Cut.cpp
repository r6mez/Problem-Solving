// D. Table Cut
// URL: https://codeforces.com/contest/2194/problem/D
// Time: 2/10/2026, 11:17:31 PM
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
    int ones = 0;
    vector<vi> a(n, vi(m)); 
    for(auto& i : a) {
        for(auto& j : i) {
            cin >> j;
            ones += j;
        }
    }
    
    int half = ones/2;
    int prod = half * (half + ones%2);

    int x = n, y = m;
    int cnt = 0;
    for (int i = 0; i < n; i++){
        for (int j = m - 1; j >= 0; j--){
            cnt += a[i][j];
            if(cnt == half) {
                x = i + 1;
                y = j + 1;
                break;
            }
        }
        if(cnt == half) break;
    }

    string path = "";
    if(x - 1) path += string(x - 1, 'D');
    if(y - 1) path += string(y - 1, 'R');
    path += "D";
    if(m - y + 1) path += string(m - y + 1, 'R');
    if(n - x) path += string(n - x, 'D');

    cout << prod << "\n";
    cout << path << "\n";
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