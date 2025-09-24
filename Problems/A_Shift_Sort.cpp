/*
    One day, I'm gonna grow wings
*/
// A. Shift Sort
// URL: https://codeforces.com/contest/2140/problem/A
// Time: 9/9/2025, 5:38:42 PM
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
const int MOD = 1000000007;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int ones = 0;
    for (int i = 0; i < n; i++){
        if(s[i] == '1') ones++;
    }

    int cnt = 0;
    for (int i = n - 1; i >= n - ones; i--){
        // cout << "i = " << i << "\n";
        if(s[i] == '0') cnt++;
    }

    finish(cnt);
}

/*
110
*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}