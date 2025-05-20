/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// C. Smilo and Monsters
// URL: https://codeforces.com/problemset/problem/1891/C
// Time: 5/19/2025, 2:07:24 PM
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
    sort(all(a));

    int x = 0, ops = 0;
    int l = 0, r = n - 1;
    while (l < r) {
        if (x + a[l] <= a[r]) {
            ops += a[l];
            x += a[l];
            a[l] = 0;
            l++;
        }
        else {
            int needed = a[r] - x;
            a[l] -= needed;
            ops += needed;
            ops += 1;
            x = 0;
            r--;
        }
    }
    
    if (l == r) {
        int A = a[l];
        if (A <= x) {
            ops += 1;
        } else {
            int diff = A - x;
            int k = (diff + 1) / 2;
            ops += min(A, k + 1);
        }
    }

    cout << ops << '\n';
}

/*
NOTES:
1 2 2 3 4 5
1 + 2 (3) + 3 [1]
steps = 4
2 + 3 (5) + 5 [1]
steps 6
1 (1)

we will store in x until x <= mn && x >= 2
    mn -= x, x = 0;

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}