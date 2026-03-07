// C. Specialty String
// URL: https://codeforces.com/contest/2200/problem/C
// Time: 3/7/2026, 4:03:32 PM
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
    int n; cin >> n;
    string s; cin >> s;
    while(true) {
        bool change = false;
        for (int i = 0; i < n - 1; i++){
            int l = i, r = i + 1;
            // make r first element to equal l with only stars between them
            if(s[l] != '*' && s[r] == '*') {
                while(r < n && s[r] == '*') {
                    r++;
                }
            }

            if(s[l] == s[r] && s[l] != '*') {
                while(l >= 0 && r < n && s[l] == s[r] && s[l] != '*') {
                    s[l] = s[r] = '*';
                    l--, r++;
                }
                change = true;
            }
        }
        if(change == false) break;
    }

    for (int i = 0; i < n; i++){
        if(s[i] != '*') finish("NO");
    }
    
    finish("YES");    
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