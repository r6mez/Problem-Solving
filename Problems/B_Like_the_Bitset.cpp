/*
    One day, I'm gonna grow wings
*/
// B. Like the Bitset
// URL: https://codeforces.com/contest/2136/problem/B
// Time: 8/28/2025, 5:52:48 PM
#include <bits/stdc++.h>
using namespace std;
#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { cin.tie(nullptr)->sync_with_stdio(false); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007;

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            cnt++;
            if (cnt >= k) {
                cout << "NO\n";
                return;
            }
        } else cnt = 0;
    }

    
    vi a(n);
    int big = n, small = 1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') a[i] = big--;
        else a[i] = small++;
    }
    
    cout << "YES\n";
    cout << a << "\n";
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