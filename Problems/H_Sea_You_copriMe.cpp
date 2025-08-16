/*
    One day, I'm gonna grow wings
*/
// H. Sea, You & copriMe
// URL: https://codeforces.com/contest/2131/problem/H
// Time: 8/13/2025, 9:08:54 PM
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

vi getPrimeFactors(int n) {
    vi p;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) n /= i, p.push_back(i);
        }
    }
    if (n > 1) p.push_back(n);
    return p;
}

void solve() {
    vi p = getPrimeFactors(124);
    cout << p << "\n";
}

/*

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}