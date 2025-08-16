/*
    One day, I'm gonna grow wings
*/
// D. Valid BFS?
// URL: https://codeforces.com/problemset/problem/1037/D
// Time: 8/15/2025, 3:03:59 PM
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
    int n;
    cin >> n;
    vector<vi> adj(n + 1);
    for (int i = 1, u, v; i < n; ++i){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vi where(n + 1), seq(n);
    for (int i = 0; i < n; ++i){
        cin >> seq[i];
        where[seq[i]] = i;
    }

    for (auto& u : adj){
        sort(all(u), [&](int u, int v){ return where[u] < where[v]; });
    }

    vi bfs;
    queue<pii> q; q.emplace(1, 0);
    while (q.size()){
        auto [u, par] = q.front(); q.pop();
        bfs.push_back(u);
        for (auto v : adj[u]) {
            if (v == par) continue;
            q.emplace(v, u);
        }
    }

    cout << (seq == bfs ? "Yes" : "No");
}

/*

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}