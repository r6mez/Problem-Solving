/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// C. Jellyfish and Green Apple
// URL: https://codeforces.com/problemset/problem/1875/C
// Time: 6/7/2025, 11:31:35 AM
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
    int n, m; cin >> n >> m;

    n %= m;
    int a = n / gcd(n, m), b = m / gcd(n, m);
    if(__builtin_popcount(b) > 1){
        cout << "-1\n";
        return;
    }
    int cnt = __builtin_popcount(a) * m - n;
    cout << cnt << "\n";
}

/*
NOTES:
3 4
2 -> (0.5, 0.5) (0.5, 0.5) (4)
1 -> (0.5, 0.5) -> (0.25, 0.25) (0.25, 0.25) (4)
*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}