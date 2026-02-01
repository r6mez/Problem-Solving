// C. Restricted Sorting
// URL: https://codeforces.com/contest/2188/problem/C
// Time: 2/1/2026, 3:25:32 PM
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
    vi a(n); cin >> a;
    vi b = a; sort(all(b));

    if (a == b) finish(-1);

    int mn = INF, mx = -INF;
    vi need_change;
    for (int i = 0; i < n; i++) {
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
        if (a[i] != b[i]) {
            need_change.push_back(a[i]);
        }
    }

    int ans = INF;
    for (int x : need_change) {
        ans = min(ans, max(abs(x - mn), abs(x - mx)));
    }

    cout << ans << "\n";
}

/*
if it's already sorted -> -1

2 1 5 4 3
2 1 3 4 5
4 1 3 2 5
1 4 3 2 5
1 2 3 4 5

for x and y that need to be swapped
we need to find maximum z which is the farest number from both
and minimize this z for each x, y
z can be min
or can be max
or can be in between x, y

1 1 4 5 1 4
what need's to change is 4 5 1 4
other elements is 1 1 

min 1
max 5
max diff between what need's to change and min/max is 4 - 1 = 3

*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}