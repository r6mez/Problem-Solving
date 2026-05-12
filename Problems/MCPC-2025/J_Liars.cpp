// J. Liars
// URL: https://codeforces.com/group/Rilx5irOux/contest/636870/problem/J
// Time: 5/12/2026, 5:28:55 PM
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

int pwmod(int a, int b, int m) {
    a %= m;
    int result = 1;
    while (b > 0) {
        if (b & 1) result = (result * a) % m;
        a = (a * a) % m;
        b /= 2;
    }
    return result;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<vi> adj(n);
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v; u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vi color(n, -1);
    function<bool(int, int)> check_bipartite = [&](int u, int currColor) -> bool { 
        color[u] = currColor;
        int bipartite = true;
        for(int v : adj[u]){
            if(color[v] == -1){
                if(!check_bipartite(v, !currColor)) return false;
            } else if (color[v] == color[u]){
                return false;
            }
        }
        
        return true;
    };

    int c = 0;
    for(int u = 0; u < n; u++){
        if(color[u] == -1){
            c++;
            if(check_bipartite(u, 0) == false){
                cout << "-1\n";
                return;
            }
        }
    }
  
    int answer = pwmod(2, c, MOD);
    cout << answer << "\n";
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