/*
  الذكرى واخداني لمكان، أيام زمان
*/
// B. Good Sequences
// URL: 0
// Time: 12/4/2025, 7:40:48 PM
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

const int N = 2e5;
vi divisor[N]; int n, s[N], mx[N];

void init() {
    for (int i = 2; i <= 1e5; i++) {
        if (divisor[i].empty()) {
            for (int j = i; j <= 100000; j += i) {
                divisor[j].push_back(i);
            }
        }
    }
}

void solve() {
    init();
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int w = 0;
        for (auto it : divisor[s[i]]) {
            w = max(w, mx[it]);
        }
        w++;
        ans = max(ans, w);
        for (auto it : divisor[s[i]]) {
            mx[it] = w;
        }
    }
    cout << ans;
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