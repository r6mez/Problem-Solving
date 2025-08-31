/*
    One day, I'm gonna grow wings
*/
// A. In the Dream
// URL: https://codeforces.com/contest/2136/problem/0
// Time: 8/28/2025, 5:37:48 PM
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
    int a, b, c, d; cin >> a >> b >> c >> d;

    bool ok = true;
    if (max(a, b) > 2 * (min(a, b) + 1)){
        ok = false;
    }

    a = c - a;
    b = d - b;

    if (max(a, b) > 2 * (min(a, b) + 1)){
        ok = false;
    }


    if(ok) cout << "YES\n";
    else cout << "NO\n";
}

/*
5 6
AABAABAABAA
min >= max / 2 - 1 >= min / 2

*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}