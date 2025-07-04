/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// Common Divisors
// URL: https://cses.fi/problemset/task/1081/
// Time: 7/2/2025, 8:09:18 PM
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
    int n; cin >> n;
    vi a(n); cin >> a;

    const int M = 1e6;
    vector<int> freq(M + 1, 0);

    for (int i = 0; i < n; i++) {
        freq[a[i]]++;
    }

    for (int g = M; g >= 1; --g) {
        int cnt = 0;
        for (int m = g; m <= M; m += g) {
            cnt += freq[m];
            if (cnt >= 2) {
                cout << g << "\n";
                return;
            }
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
    // cin >> t;
    while (t--) Ramez();
    return 0;
}