/*
    One day, I'm gonna grow wings
*/
// C. Make it Equal
// URL: https://codeforces.com/contest/2131/problem/C
// Time: 8/13/2025, 7:40:47 PM
#include <bits/stdc++.h>
using namespace std;
#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { cin.tie(nullptr)->sync_with_stdio(false); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007;

void solve() {
    int n, k; cin >> n >> k;
    vi s(n), t(n);
    cin >> s >> t;

    map<int, int> cs, ct;

    for (int x : s) {
        int r = x % k;
        cs[r]++;
    }

    for (int x : t) {
        int r = x % k;
        ct[r]++;
    }

    if (cs[0] != ct[0]) {
        cout << "NO\n";
        return;
    }

    if (k % 2 == 0) {
        int mid = k / 2;
        if (cs[mid] != ct[mid]) {
            cout << "NO\n";
            return;
        }
    }

    set<int> keys;

    for (auto& p : cs) keys.insert(p.first);
    for (auto& p : ct) keys.insert(p.first);

    for (int r : keys) {
        if (r == 0) continue;
        if (k % 2 == 0 && r == k / 2) continue;

        if (cs[r] + cs[k - r] != ct[r] + ct[k - r]) {
            cout << "NO\n";
            return;
        }
    }


    cout << "YES\n";
}

/*
y in s such that
y + c*k = x
y - c*k = -x

x __ y __ (-x)


*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}