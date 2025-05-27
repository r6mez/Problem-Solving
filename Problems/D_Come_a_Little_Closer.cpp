/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// D. Come a Little Closer
// URL: https://codeforces.com/contest/2114/problem/D
// Time: 5/26/2025, 6:35:59 PM
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
    vector<pii> v(n);
    vi x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
        x[i] = v[i].first;
        y[i] = v[i].second;
    }

    if (n == 1) {
        cout << 1 << "\n";
        return;
    }

    vector<int> xs = x, ys = y;
    sort(all(xs)); sort(all(ys));

    int xmin1 = xs[0], xmin2 = xs[1];
    int xmax1 = xs[n - 1], xmax2 = xs[n - 2];
    int ymin1 = ys[0], ymin2 = ys[1];
    int ymax1 = ys[n - 1], ymax2 = ys[n - 2];

    int ans = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        int xl = (v[i].first == xmin1 ? xmin2 : xmin1);
        int xh = (v[i].first == xmax1 ? xmax2 : xmax1);
        int yl = (v[i].second == ymin1 ? ymin2 : ymin1);
        int yh = (v[i].second == ymax1 ? ymax2 : ymax1);

        int w = xh - xl + 1;
        int h = yh - yl + 1;
        int cost = w * h;
        
        if (cost == n - 1) cost += min(w, h);
        ans = min(ans, cost);
    }

    cout << ans << '\n';
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