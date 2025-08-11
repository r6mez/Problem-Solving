/*
    I was alone in an empty universe.
    A universe too small and at the same time... too infinite.
*/
// Subordinates
// URL: https://cses.fi/problemset/task/1674
// Time: 8/7/2025, 4:13:55 PM
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

const int maxN = 2e5;
int sz[maxN+1];
vi G[maxN+1];

void dfs(int u){
    sz[u] = 1;
    for(int v : G[u]){
        dfs(v);
        sz[u] += sz[v];
    }
}

void Ramez() {
    int n; cin >> n;
    for (int v = 2; v <= n; v++){
        int u; cin >> u;
        G[u].push_back(v);
    }
    
    dfs(1);

    for (int i = 1; i <= n; i++){
        cout << sz[i] - 1 << " ";
    }
}

/*

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}