/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// C. Mex in the Grid
// URL: https://codeforces.com/contest/2102/problem/C
// Time: 5/11/2025, 6:21:12 PM
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

bool check(int i, int j, int n){
    return (i >= 0 && i < n && j >= 0 && j < n);
}

void Ramez() {
    int n; cin >> n;
    int cnt = 0;
    vector<vi> grid(n, vi(n));

    int mid = (n - 1) / 2;
    int totLayers = max(mid, n - mid - 1);
    vector<pii> p; p.push_back({mid, mid});

    for (int layer = 1; layer <= totLayers; ++layer) {
        int i = mid - layer + 1;  int j = mid + layer;
        p.push_back({i, j});
        for (int k = 0; k < 2 * layer - 1; ++k) if (check(++i, j, n)) p.push_back({i, j});
        for (int k = 0; k < 2 * layer; ++k) if (check(i, --j, n)) p.push_back({i, j});
        for (int k = 0; k < 2 * layer; ++k) if (check(--i, j, n)) p.push_back({i, j});
        for (int k = 0; k < 2 * layer; ++k) if (check(i, ++j, n)) p.push_back({i, j});
    }

    for (int o = 0; o < p.size(); ++o) grid[p[o].first][p[o].second] = o;
    for (int i = 0; i < n; ++i) cout << grid[i] << "\n";
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