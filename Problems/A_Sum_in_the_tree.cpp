/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// A. Sum in the tree
// URL: https://codeforces.com/problemset/problem/1098/A
// Time: 7/10/2025, 9:37:26 PM
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
    vi p(n + 1), s(n + 1); p[1] = 1;
    vector<vi> adj(n + 1);

    for (int i = 2; i <= n; i++){
        cin >> p[i];
        adj[p[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++){
        cin >> s[i];
    }
    
    int totalSum = 0;
    bool madeMistake = false;
    function<void(int, int)> dfs = [&](int u, int lastSum) -> void {
         if (madeMistake) return;

        if (s[u] == -1) {
            if (!adj[u].empty()) {
                int mnChildS = LLONG_MAX;
                for (int v : adj[u]) mnChildS = min(mnChildS, s[v]);
                s[u] = mnChildS;
            } else {
                s[u] = lastSum;
            }
        }

        if(s[u] < lastSum) madeMistake = true;
        
        totalSum += s[u] - lastSum;
        for(int v : adj[u]){
            dfs(v, s[u]);
        }
    };
    
    dfs(1, 0);
    
    if(madeMistake) cout << "-1\n";
    else cout << totalSum << "\n";
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