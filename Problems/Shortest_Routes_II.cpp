/*
    I thought I could bring an end to the world's suffering,
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// Shortest Routes II
// URL: https://cses.fi/problemset/task/1672
// Time: 3/26/2025, 8:08:37 PM
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

// Floyd-Warshall Algorithm
void Ramez() {
    int n, m, q; cin >> n >> m >> q;

    vector<vi> dis(n + 1, vi(n + 1, LLONG_MAX));

    for (int i = 1; i <= n; i++) {
        dis[i][i] = 0;
    }


    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        dis[a][b] = min(dis[a][b], c);
        dis[b][a] = min(dis[b][a], c);
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dis[i][k] < LLONG_MAX && dis[k][j] < LLONG_MAX)
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }

    while (q--) {
        int a, b; cin >> a >> b;
        if (dis[a][b] == LLONG_MAX) cout << "-1\n";
        else cout << dis[a][b] << "\n";
    }
}

/*
NOTES:

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}