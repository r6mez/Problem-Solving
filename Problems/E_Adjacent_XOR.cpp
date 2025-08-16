/*
    One day, I'm gonna grow wings
*/
// E. Adjacent XOR
// URL: https://codeforces.com/contest/2131/problem/E
// Time: 8/13/2025, 8:50:33 PM
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
    int n; cin >> n;
    vi a(n), b(n); cin >> a >> b;

    bool ok = true;
    if (a[n - 1] != b[n - 1]) ok = false;
    for (int i = n - 2; ok && i >= 0; --i) {
        if (b[i] == a[i]) continue;
        if (b[i] == (a[i] ^ a[i + 1])) continue;
        if (b[i] == (a[i] ^ b[i + 1])) continue;
        ok = false;
    }
    cout << (ok ? "YES\n" : "NO\n");
}

/*

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}