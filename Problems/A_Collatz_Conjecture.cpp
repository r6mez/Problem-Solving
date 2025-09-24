/*
    One day, I'm gonna grow wings
*/
// A. Collatz Conjecture
// URL: https://codeforces.com/contest/2137/problem/A
// Time: 9/7/2025, 5:35:22 PM
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

int calc(int k, int n) {
    if (k == 0) {
        return n;
    }

    if ((n - 1) % 3 == 0) {
        int prev = (n - 1) / 3;
        if (prev > 0 && (prev % 2 != 0)) return calc(k - 1, prev);
    }
    
    return calc(k - 1, n * 2);
}

void solve() {
    int k, n; cin >> k >> n;
    cout << calc(k, n) << "\n";
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