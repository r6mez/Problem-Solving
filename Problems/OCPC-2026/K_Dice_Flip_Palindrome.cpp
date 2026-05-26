// K. Dice Flip Palindrome
// URL: https://codeforces.com/group/Rilx5irOux/contest/686782/problem/K
// Time: 5/25/2026, 2:20:45 PM
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
    string s; cin >> s;
    for (char &c : s) {
        if(c == '1' || c == '6') c = '0';
        else if(c == '2' || c == '5') c = '1';
        else if(c == '3' || c == '4') c = '2';
    }

    string t = s;
    reverse(all(t));
    if(t == s) cout << "YES\n";
    else cout << "NO\n";
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