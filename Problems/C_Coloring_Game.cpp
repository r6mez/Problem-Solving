/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// C. Coloring Game
// URL: https://codeforces.com/contest/2112/problem/C
// Time: 6/23/2025, 5:56:13 PM
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

    int cnt = 0;

    for (int l = 1; l < n; l++) {
        for (int m = 1; m < l; m++) {
            int r = upper_bound(a.begin(), a.begin() + m, max(a[l], a[n - 1] - a[l]) - a[m]) - a.begin();
            cnt += (m - r);
        }
    }

    cout << cnt << "\n";
}

/*
NOTES:
a , b , c
a + b > c
c > b

7 7 7 7 7

1 1 2 2 4
1 2 2
2 2 4

2 3 3 4 5 5
- - -
- -   -
- -     -
- -       -
-   - -
-     - -
-       - -


  - - -
  - -   -
  - -     -
  -   - -
  -     - -


    - - -
    - -   -
    -   - -

      - - -

(n - 2) + (n - 3)
*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}