/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// B. SUMdamental Decomposition
// URL: https://codeforces.com/contest/2108/problem/B
// Time: 5/2/2025, 8:05:00 PM
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
    int n, x;cin >> n >> x;
    int bits = __builtin_popcountll(x);
    if (n <= bits) { cout << x << "\n";return; }
    if ((n - bits) % 2 == 0)cout << x + n - bits << "\n";
    else {
        if (x > 1) { cout << x + n - bits + 1 << "\n";return; }
        if (x == 1) { cout << n + 3 << "\n";return; }
        else {
            if (n == 1) { cout << -1 << "\n";return; }
            else cout << n + 3 << "\n";
        }
    }
}

/*
NOTES:

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}