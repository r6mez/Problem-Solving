// B. Count Primeful Subtrees
// URL: https://codeforces.com/group/Rilx5irOux/contest/638270/problem/B
// Time: 5/13/2026, 3:22:59 PM
#include <algorithm>
#include <bits/stdc++.h>
#include <utility>
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

set<int> getPrimeFactors(int n) {
    set<int> p;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) n /= i, p.insert(i);
        }
    }
    if (n > 1) p.insert(n);
    return p;
}

vector<set<int>> s;

int merge(int a, int b){
    if(s[a].size() < s[b].size()) swap(a, b);
    for(int x : s[b]) s[a].insert(x);
    s[b].clear();
    return a;
}

void solve() {
    int n; cin >> n;
    
    s.resize(n);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        s[i] = getPrimeFactors(a);
    }
    
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int count = 0;
    function<int(int, int)> dfs = [&](int u, int p) -> int {
        int root = u;
        for(int v : adj[u]){
            if(v == p) continue;
            root = merge(root, dfs(v, u));
        }

        if(s[root].size() % 2 == 1) count++;
        return root;
    };

    dfs(0, -1);
    cout << count << "\n";
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