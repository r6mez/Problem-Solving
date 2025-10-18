/*
    One day, I'm gonna grow wings
*/
// D. Ones and Twos
// URL: https://codeforces.com/problemset/problem/1896/D
// Time: 10/10/2025, 4:44:52 PM
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
    int n, q; cin >> n >> q;
    vector<int> a(n);
    set<int> pos;
    for (int i = 0;i < n;i++) { cin >> a[i]; if (a[i] == 1) pos.insert(i); }
    while (q--) {
        int cmd; cin >> cmd;
        if (cmd == 1) {
            int v; cin >> v;
            int num = pos.size();
            if (((v - num) & 1) == 0) {
                if (v <= 2 * n - num) cout << "YES\n"; else cout << "NO\n";
            }
            else {
                if (num == 0) cout << "NO\n";
                else {
                    int s1 = 2 * *pos.rbegin() - (num - 1);
                    int s2 = 2 * (n - *pos.begin() - 1) - (num - 1);
                    if (v <= max(s1, s2)) cout << "YES\n"; else cout << "NO\n";
                }
            }
        }
        else {
            int idx, v; cin >> idx >> v; idx--;
            if (a[idx] == 1) pos.erase(idx);
            a[idx] = v;
            if (a[idx] == 1) pos.insert(idx);
        }
    }
}

/*
s == a[j] - a[i - 1]
a[j] = s - a[i - 1]
*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}