// A. Love Triangle
// URL: https://codeforces.com/contest/939/problem/A
// Time: 3/12/2026, 5:31:25 PM
#include <bits/stdc++.h>
using namespace std;
#define int         long long
#define vi          vector<int>
#define pii         pair<int, int>
#define all(v)      v.begin(), v.end()
#define finish(s)   { cout << s << "\n"; return; }
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { cin.tie(nullptr)->sync_with_stdio(false); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007, INF = 2e18;

void solve() {
    int n; cin >> n;
    vi a(n); for(int &i : a) cin >> i, i--;

    for (int i = 0; i < n; i++){
        if (i == a[a[a[i]]]) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
}

/*
a[A] = B
a[a[A]] = a[B] = C
a[a[a[A]]] = a[a[B]] = a[C] = A

a[A]

*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) solve();
}