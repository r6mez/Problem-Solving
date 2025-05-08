/*
    I thought I could bring an end to the world's suffering,
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// High Score
// URL: https://cses.fi/problemset/task/1673
// Time: 3/26/2025, 8:39:22 PM
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

struct edge {
    int u, v, w;
};

// Bellman-Ford Algorithm (Maximum Score)
void Ramez() {
    int n, m; cin >> n >> m;

    vector<edge> edges;

    for (int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    
    vi score(n + 1, LLONG_MIN);
    score[1] = 0;

    // Relaxation (n - 1) times
    for (int i = 1; i <= n - 1; i++){
        for (int j = 0; j < m; j++){
            auto [u, v, w] = edges[j];
            if(score[u] != LLONG_MIN){
                score[v] = max(score[v], score[u] + w);
            }
        }
    }


    /*
    After the initial relaxation steps, we check if any edge can still be relaxed.
    If it can, that means there's a cycle (specifically a "positive cycle" for maximizing the score) 
    that can improve the score.
    */
    vector<bool> hasPositiveCycle(n + 1, false);
    for (int i = 0; i < m; i++){
        auto [u, v, w] = edges[i];
        if(score[u] != LLONG_MIN && score[v] < score[u] + w){
            hasPositiveCycle[v] = true;
        }
    }

    /*
    However, simply detecting an edge that can be relaxed doesn't tell us which vertices
    might be affected downstream by this cycle.
    The propagation loop iterates over all edges several times (in this case, n times) 
    to "spread" the effect of the positive cycle
    */
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            auto [u, v, w] = edges[j];
            if(hasPositiveCycle[u]) hasPositiveCycle[v] = true;
        }
    }

    if(hasPositiveCycle[n]) cout << -1 << "\n";
    else cout << score[n] << "\n";
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