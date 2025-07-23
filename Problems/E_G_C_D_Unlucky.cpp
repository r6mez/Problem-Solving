/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// E. G-C-D, Unlucky!
// URL: https://codeforces.com/contest/2126/problem/E
// Time: 7/17/2025, 6:19:43 PM
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
    vi p(n), s(n); cin >> p >> s;

    if (n == 1) {
        if(p[0] == s[0]) cout << "YES\n";
        else cout << "NO\n";
        return;
    }

    bool ok = true;

    for (int i = 0; i < n - 1; i++) {
        if (p[i] % p[i + 1]) {
            ok = false;
            break;
        }
        if (s[i + 1] % s[i]) {
            ok = false;
            break;
        }
    }

    if (p[n - 1] != s[0]) ok = false;

    for (int i = 1; i < n - 1; i++) {
        if (gcd(p[i - 1], lcm(p[i], s[i])) != p[i]) { ok = false; break; }
        if (gcd(s[i + 1], lcm(p[i], s[i])) != s[i]) { ok = false; break; }
    }

    if (gcd(p[0], s[1]) != s[0]) ok = false;
    if (gcd(p[n - 2], s[n - 1]) != p[n - 1]) ok = false;

    if (ok) cout << "YES\n";
    else cout << "NO\n";
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