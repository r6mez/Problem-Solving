/*
    One day, I'm gonna grow wings
*/
// C. DNA Alignment
// URL: https://codeforces.com/contest/520/problem/C
// Time: 8/18/2025, 12:17:20 PM
#include <bits/stdc++.h>
using namespace std;
#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> auto& operator<<(auto& o, vector<T>& v) { for (auto& e : v) o << e << ' '; return o; }
template<typename T> auto& operator>>(auto& i, vector<T>& v) { for (auto& e : v) i >> e; return i; }
void FastIO() { cin.tie(nullptr)->sync_with_stdio(false); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007;

int powmod(int a, int b, int m) {
    a %= m;
    int result = 1;
    while (b > 0) {
        if (b & 1) result = (result * a) % m;;
        a = (a * a) % m;
        b /= 2;
    }
    return result;
}

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vi v(4, 0);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') v[0]++;
        else if (s[i] == 'C') v[1]++;
        else if (s[i] == 'T') v[2]++;
        else if (s[i] == 'G') v[3]++;
    }
    int x = 0, mx = 0;
    for (int i = 0; i < 4;i++) {
        if (v[i] > mx) mx = v[i], x = 1;
        else if (v[i] == mx) x++;
    }

    cout << powmod(x, n, MOD) << '\n';
}

/*§

*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) solve();
}