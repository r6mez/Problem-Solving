/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// B. SUMdamental Decomposition
// URL: https://codeforces.com/contest/2108/problem/B
// Time: 5/1/2025, 5:54:42 PM
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
    int n, x; cin >> n >> x;
    if (n == 1) {
        if(x == 0) cout << "-1\n";
        else cout << x << "\n";
    }
    else if (n == 2) {
        if (x == 0) cout << 1 + 1 << "\n";
        else if (x == 1) cout << 2 + 3 << "\n";
        else cout << (1 ^ x) + 1 << "\n";
    }
    else if (n >= 3) {
        if (x == 0) {
            if (n % 2 == 0) cout << n << "\n";
            else cout << (n - 3) + 1 + 2 + 3 << "\n";
        }
        else {
            int ones = __builtin_popcountll(x), zeros = n - ones;
            if (zeros % 2 == 0) {
                cout << x + zeros << "\n";
            }
            else {
                if (ones < 2) cout << x + (zeros - 3) + 1 + 2 + 3 << "\n";
                else cout << x + (zeros + 1) << "\n";
            }
        }
    }
}


/*
NOTES

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}