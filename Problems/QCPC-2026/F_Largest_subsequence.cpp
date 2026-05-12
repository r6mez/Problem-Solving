// F. Largest subsequence
// URL: https://codeforces.com/group/Rilx5irOux/contest/636158/problem/F
// Time: 5/8/2026, 9:36:12 PM
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
    int n, m; cin >> n >> m;
    string x, y; cin >> x >> y;

    int need[26] = {};
    for (char c : y) need[c - 'a']++;

    vector<array<int, 26>> suf(n + 1), nxt(n + 1);

    for (int i = n - 1; i >= 0; i--) {
        suf[i] = suf[i + 1];
        nxt[i] = nxt[i + 1];
        int c = x[i] - 'a';
        suf[i][c]++;
        nxt[i][c] = i;
    }

    for (int c = 0; c < 26; c++) {
        if (suf[0][c] < need[c]) {
            cout << "-1\n";
            return;
        }
    }

    string res;
    int pos = 0;

    for (int step = 0; step < m; step++) {
        for (int c = 25; c >= 0; c--) {
            if (need[c] == 0) continue;

            int j = nxt[pos][c];
            if (j == n) continue;

            bool ok = true;
            for (int d = 0; d < 26; d++) {
                int required = need[d] - (d == c ? 1 : 0);
                if (suf[j + 1][d] < required) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                res += 'a' + c;
                need[c]--;
                pos = j + 1;
                break;
            }
        }
    }

    cout << res << "\n";
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