/*
    I thought I could bring an end to the world's suffering,
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// B. Road Construction
// URL: https://codeforces.com/contest/330/problem/B
// Time: 4/3/2025, 12:11:57 PM
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
    int n, m; cin >> n >> m;
    vector<set<int>> adj(n + 1);
    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }

    vector<pii> edges;

    for (int i = 1; i <= n; i++){
        if(adj[i].size() == 0){
            for (int j = 1; j <= n; j++){
                if(i == j) continue;
                edges.push_back({i, j});    
            }
            break;
        }
    }
    

    cout << edges.size() << "\n";
    for(auto &[i, j] : edges){
        cout << i << " " << j << "\n";
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