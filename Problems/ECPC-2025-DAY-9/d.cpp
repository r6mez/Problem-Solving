#include <bits/stdc++.h>
using namespace std;
#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("file.txt", "r", stdin); }
const int MOD = 1000000007;


void solve() {
    int n, m, k; cin >> n >> m >> k;
    vi a(n); cin >> a;

    const int INF = 1e18;
    vi best(n, INF); // best[pos] = minimal time-since-last-oxygen when we visited pos

    function<bool(int, int)> track = [&](int curr, int t) -> bool {
        if (curr >= n) return false;
        if (a[curr] == 3) return false;

        if (a[curr] == 2) t = 0;

        if (t > k) return false;

        if (curr == n - 1) return true;

        if (t >= best[curr]) return false;
        best[curr] = t;

        if(a[curr] == 1){
            int v = curr + 1;
            if (v >= n || a[v] == 3) return false;
            if (track(v, (a[v] == 2? 0 : t + 1))) return true;
        }
           
        if (a[curr] == 2) {
            for (int dist = 1; dist <= m; ++dist) {
                int v1 = curr + dist;
                if (v1 < n && a[v1] != 3) {
                    if (track(v1, a[v1] == 2? 0 : 1)) return true;
                }
            }
        }

        return false;
    };

    cout << (track(0, 0) ? "YES" : "NO");
}

/*

*/

int32_t main() {
    UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}