/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// D. Retaliation
// URL: https://codeforces.com/contest/2117/problem/D
// Time: 6/8/2025, 6:45:36 PM
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


    if ((n * a[n - 1] - a[0]) % (n * n - 1) != 0) {
        cout << "NO\n";
        return;
    }

    int x = (n * a[n - 1] - a[0]) / (n * n - 1);

    if ((a[0] - x) % n != 0) {
        cout << "NO\n";
        return;
    }

    int y = (a[0] - x) / n;

    if (x < 0 || y < 0) {
        cout << "NO\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        if (a[i] != x * (i + 1) + y * (n - i)) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

/*
NOTES:
a[0] = x + n*y
a[n-1] = n*x + y

x = (n*a[n-1] - a[0]) / (n*n - 1)
y = (a[0] - x) / n

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}