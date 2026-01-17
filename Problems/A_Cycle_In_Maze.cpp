// A. Cycle In Maze
// URL: https://codeforces.com/gym/621178/problem/A
// Time: 12/10/2025, 3:23:28 PM
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


int di[4] = { 1,  0, 0, -1 };
int dj[4] = { 0, -1, 1,  0 };

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<string> g(n); cin >> g;

    int x, y;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'X') {
                x = i;
                y = j;
            }
        }
    }

    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int, int>> q;
    dist[x][y] = 0;
    q.push({ x, y });

    while (!q.empty()) {
        auto p = q.front(); q.pop();
        int i = p.first, j = p.second;
        for (int z = 0; z < 4; z++) {
            int ni = i + di[z], nj = j + dj[z];
            if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
            if (g[ni][nj] == '*') continue;
            if (dist[ni][nj] == -1) { dist[ni][nj] = dist[i][j] + 1; q.push({ ni,nj }); }
        }
    }

    string path = "";
    int ci = x, cj = y;
    string mv = "DLRU";
    for (int step = 0; step < k; step++) {
        bool ok = false;
        for (int z = 0; z < 4; z++) {
            int ni = ci + di[z], nj = cj + dj[z];
            if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
            if (g[ni][nj] == '*') continue;
            if (dist[ni][nj] == -1) continue;
            int rem = k - step - 1;
            if (dist[ni][nj] <= rem) {
                path += mv[z];
                ci = ni; cj = nj;
                ok = true;
                break;
            }
        }

        if (!ok) { cout << "IMPOSSIBLE\n"; return; }
    }

    cout << path << "\n";
}

/*
D L R U
*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) solve();
}