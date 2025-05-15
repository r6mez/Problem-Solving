/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// A. Dinner Time
// URL: https://codeforces.com/contest/2102/problem/0
// Time: 5/11/2025, 5:35:08 PM
#include <bits/stdc++.h>
using namespace std;
#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007;

void Ramez() {
    int n, m, p, q; cin >> n >> m >> p >> q;
    if (n % p == 0 && (n / p) * q != m) cout << "NO\n";
    else cout << "YES\n";
}

/*
NOTES:
n % p && (n / p) * q == m 
*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}