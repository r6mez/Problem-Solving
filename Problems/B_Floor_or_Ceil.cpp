/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// B. Floor or Ceil
// URL: https://codeforces.com/problemset/problem/2082/B
// Time: 7/6/2025, 8:30:47 PM
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

int f(int x, int n) {
    while (n--) {
        if (x == 0) return x;
        x = (x >> 1);
    }
    return x;
}

int g(int x, int n) {
    while (n--) {
        if (x <= 1) return x;
        x = ((x + 1) >> 1);
    }
    return x;
}

void Ramez() {
    int x, n, m;
    cin >> x >> n >> m;
    cout << f(g(x, m), n) << " " << g(f(x, n), m) << endl;
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
