/*
    I thought I could bring an end to the world's suffering,
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// D. Arcology On Permafrost
// URL: https://codeforces.com/contest/2084/problem/D
// Time: 4/5/2025, 6:04:22 PM
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
    int n, m, k; cin >> n >> m >> k;

    int x = max(n - m * k, n / (m + 1));

    vi a(n);

    for (int i = 0; i < x; i++) {
        for (int j = i; j < n; j += x) {
            a[j] = i;
        }
    }

    cout << a << "\n";
}

/*
NOTES:
6 1 4 -> 2
n - m * k = 2;
0 1 2 0 1 2 -> 0
0 1 2 2 1 0 -> 1
0 1 1 0 0 1 -> 2
0 1 0 1 0 1 -> 2
0 0 1 1 0 0

8 1 5 -> 3
n - m * k = 3;
0 1 2 2 1 0 0 1 -> 2
0 1 2 0 1 2 0 1 -> 2
0 1 2 1 0 1 2 1 -> 1'
0 1 2 3 4 0 1 2

11 3 3 -> 2
n - m * k = 2;
1 0 0 1 0 1 1 0 1 1 0


22 6 3 -> 3
n - m * k = 4
0 2 1 0 2 1 0 3 2 1 0 2 1 0 2 1 0 2 1 0 2 1
0 0 2 1
0 1 2 0 1 2 0 1 2 0

17 2 2 -> 5
n - (m * k) = 13 (13 / 2 = 6)
0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0
0 1 2 3 4 0 1 2 3 4 0 1 2 3 4 0 1

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}