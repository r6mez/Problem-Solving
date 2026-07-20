// E. Inner Product
// URL: https://codeforces.com/group/zZYq310uLQ/contest/702561/problem/E
// Time: 7/13/2026, 4:01:12 PM
#include <bits/stdc++.h>
#include <climits>
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
    vi a(n); cin >> a;
    string s; cin >> s;
    vi b(n);

    vi L(n, 1), R(n, 1);
    for (int i = 1; i < n; i++) {
        if (s[i - 1] == '<') L[i] = L[i - 1] + 1;
        else if (s[i - 1] == '=') L[i] = L[i - 1];
    }
    for (int i = n - 2; i >= 0; i--) {
        if (s[i] == '>') R[i] = R[i + 1] + 1;
        else if (s[i] == '=') R[i] = R[i + 1];
    }

    int total = 0;
    for (int i = 0; i < n; i++) {
        b[i] = max(L[i], R[i]);
        total += a[i] * b[i];
    }
    cout << total << "\n";
    cout << b << "\n";

}

/*

*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) solve();
}