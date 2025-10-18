/*
    One day, I'm gonna grow wings
*/
// C. Rabbits
// URL: https://codeforces.com/problemset/problem/2147/C
// Time: 10/11/2025, 5:46:21 PM
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
    string s; cin >> s;
    bool ok = true;
    bool curr = (s[0] == '1');
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0')
            cnt++;
        if (i == 0)
            continue;
        if (s[i] == s[i - 1] && s[i] == '0')
            curr = false;
        if (s[i] == s[i - 1] && s[i] == '1') {
            if (curr && cnt % 2 == 1)
                ok = false;
            curr = true;
            cnt = 0;
        }
    }

    if (curr && cnt % 2 == 1 && s[n - 1] == '1')
        ok = false;

    cout << (ok ? "YES" : "NO") << "\n";
}

/*

*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}