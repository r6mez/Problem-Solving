/*
    One day, I'm gonna grow wings
*/
// D. Catshock
// URL: https://codeforces.com/contest/2154/problem/D
// Time: 10/23/2025, 9:50:43 PM
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

vector<vi> g;
vector<int> dep, par;

void dfs(int v) {
    for (int i : g[v]) {
        if (i == par[v]) continue;
        dep[i] = dep[v] ^ 1;
        par[i] = v;
        dfs(i);
    }
}

void solve() {
    int n; cin >> n;
    g.assign(n, {});
    par.assign(n, -1);
    dep.assign(n, 0);

    vi pw(n);
    
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y; --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
        ++pw[x];
        ++pw[y];
    }

    dfs(0);

    vi leafs;
    for (int i = 0; i < n - 1; ++i) {
        if (pw[i] == 1) leafs.push_back(i);
    }

    int cur = 0;
    vector<pii> ans;

    auto oper_1 = [&]() {
        ans.emplace_back(1, 1);
        cur ^= 1;
    };

    auto oper_2 = [&](int v) {
        ans.emplace_back(2, v);
        for (int i : g[v]) {
            --pw[i];
            if (i != n - 1 && pw[i] == 1) leafs.push_back(i);
        }
    };

    while (!leafs.empty()) {
        int leaf = leafs.back(); leafs.pop_back();

        if (dep[leaf] == cur) oper_1();

        oper_2(leaf);

        if (!leafs.empty()) oper_1();
    }

    cout << ans.size() << "\n";
    for (auto i : ans) {
        if (i.first == 1) cout << "1\n";
        else cout << i.first << " " << i.second + 1 << "\n";
    }
}


/*

*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}