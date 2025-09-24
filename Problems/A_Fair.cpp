/*
    One day, I'm gonna grow wings
*/
// A. Fair
// URL: https://codeforces.com/problemset/problem/986/A
// Time: 9/3/2025, 4:14:25 PM
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
    int n, m, k, s; cin >> n >> m >> k >> s;
    vector<vi> g(n + 1);
    vi a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<vi> v(n + 1, vi(k + 1, 1e7));

    for (int i = 1; i <= k; i++)
    {
        queue<int> q;
        vi dist(n + 1, 0);
        vector<bool> vis(n + 1, 0);
        for (int j = 1; j <= n; j++)
            if (a[j] == i)
                q.push(j), vis[j] = 1;

        while (!q.empty())
        {
            int u = q.front(); q.pop();
            v[u][i] = dist[u];
            for (int v : g[u]){
                if (!vis[v]){
                    vis[v] = 1;
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        sort(all(v[i]));
        int mn = 0;
        for (int j = 0; j < s; j++)
            mn += v[i][j];

        cout << mn << " ";
    }
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