/*
    One day, I'm gonna grow wings
*/
// E. Minimal Labels
// URL: https://codeforces.com/problemset/problem/825/E
// Time: 9/2/2025, 11:17:29 AM
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

vi topologicalSort(int n, vector<vi>& adj, vi& inDeg) {
    priority_queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (inDeg[i] == 0)
            q.push(i);
    }

    int curr = n;
    vi order(n + 1);

    while (!q.empty()) {
        int parent = q.top(); q.pop();
        order[parent] = curr--;
        for (int child : adj[parent]) {
            if (--inDeg[child] == 0)
                q.push(child);
        }
    }
    
    return order;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<vi> radj(n + 1);
    vi outDeg(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        radj[v].push_back(u);
        outDeg[u]++;
    }

    vi sorted = topologicalSort(n, radj, outDeg);

    for (int i = 1; i <= n; i++){
        cout << sorted[i] << " ";
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