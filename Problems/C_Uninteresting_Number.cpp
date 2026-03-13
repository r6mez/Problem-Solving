// C. Uninteresting Number
// URL: https://codeforces.com/contest/2050/problem/C
// Time: 3/12/2026, 8:15:05 PM
#include <bits/stdc++.h>
using namespace std;
#define int         long long
void FastIO() { cin.tie(nullptr)->sync_with_stdio(false); }

void solve() {
    string s; cin >> s;
    int sum = 0;
    map<int, int> m;
    for (auto i : s) {
        m[i - '0']++;
        sum += i - '0';
    }

    for (int x = 0; x <= m[2]; x++) {
        for (int y = 0; y <= m[3]; y++) {
            if (((2 * x + 6 * y) + sum) % 9 == 0) {
                cout << "YES\n";
                return;
            }
        }
    }

    cout << "NO\n";
}

signed main() {
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}