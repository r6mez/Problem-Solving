// E. New Year's Gifts
// URL: https://codeforces.com/contest/2182/problem/E
// Time: 1/25/2026, 4:32:46 PM
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
    int n, m, k; cin >> n >> m >> k;
    vector<vi> ev(m);
    
    for (int i = 0; i < m; ++i) {
        int x; cin >> x;
        ev[x - 1].push_back(-1);
    }

    for (int i = 0; i < n; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        ev[x - 1].push_back(z - y);
        k -= y;
    }
    
    int ans = 0;
    multiset<int> s;
    for (int i = 0; i < m; ++i) {
        reverse(ev[i].begin(), ev[i].end());
        for (int x : ev[i]) {
            if (x == -1) {
                if (!s.empty()) {
                    s.erase(--s.end());
                    ++ans;
                }
            }
            else {
                s.insert(x);
            }
        }
    }
    
    while (!s.empty() && *s.begin() <= k) {
        k -= *s.begin();
        s.erase(s.begin());
        ++ans;
    }
    
    cout << ans << '\n';
}

/*
k coins

n friends
y_i - should give i-th friend a gift worth at least y_i
friend will be happy if:
- the beauty of the box is at least x_i
- the gift worth is at least z_i (z_i > y_i)

m boxes
a_i - beauty of the i-th box

every friend must be bought one gift
but not all of them comes with boxes

sum of y_i <= k
n, m <= 2e5

required:
the maximum possible number of friends Monocarp can make happy if he has k coins.
*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}