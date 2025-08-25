/*
    One day, I'm gonna grow wings
*/
// C1. The Cunning Seller (easy version)
// URL: https://codeforces.com/contest/2132/problem/C1
// Time: 8/21/2025, 5:59:59 PM
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

void solve() {
    int n; cin >> n;

    int cost = 0, x = 0, a = 1;

    while (n > 0) {
        cost += (n % 3) * (a * 3 + x * (a / 3));
        n /= 3;
        a *= 3;
        x++;
    }

    cout << cost << endl;
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