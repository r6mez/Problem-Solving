// C. Broken Keyboard
// URL: https://codeforces.com/group/Rilx5irOux/contest/686782/problem/C
// Time: 5/25/2026, 2:53:32 PM
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
    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();
    int i = 0, j = 0;    
    bool fix = false;
    while(true){
        if(i >= n && j >= m) break;
        if(i < n && j < m && s[i] == t[j]){
            if(j < m - 1 && s[i] == t[j + 1]){
                i++; j+= 2;
            } else if (fix == false){
                fix = true;
                i++; j++;
            } else {
                finish("NO");
            }
        } else {
            finish("NO");
        }
    }
    cout << "YES\n";
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