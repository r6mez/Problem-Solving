/*
    One day, I'm gonna grow wings
*/
// C. Prepend and Append
// URL: https://codeforces.com/contest/1791/problem/C
// Time: 10/24/2025, 2:08:36 PM
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

    int l = 0, r = n - 1;
    while(l <= r){
        if(s[l] != s[r]){
            l++;
            r--;
            continue;
        }

        cout << r - l + 1 << "\n";
        return;
    }
    
    cout << 0 << "\n";
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