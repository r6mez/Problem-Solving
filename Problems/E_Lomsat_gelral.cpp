// E. Lomsat gelral
// URL: https://codeforces.com/contest/600/problem/E
// Time: 5/14/2026, 9:52:23 PM
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


struct Info {
    map<int, int> freq;   // color -> count
    int maxFreq = 0;
    int sumOfMax = 0;     // sum of colors with maxFreq
};

vector<Info> info;

void addColor(Info& a, int color, int count) {
    int& f = a.freq[color];
    if (f == a.maxFreq) a.sumOfMax -= color;

    f += count;

    if (f > a.maxFreq) {
        a.maxFreq = f;
        a.sumOfMax = color;
    } else if (f == a.maxFreq) {
        a.sumOfMax += color;
    }
}

int merge(int a, int b) {
    if (info[a].freq.size() < info[b].freq.size()) swap(a, b);
    for (auto [color, cnt] : info[b].freq) {
        addColor(info[a], color, cnt);
    }
    info[b].freq.clear();
    return a;
}

void solve() {
    int n; cin >> n;
    
    info.resize(n);

    for(int i = 0; i < n; i++){
        int x; cin >> x;
        info[i].freq[x]++;
        info[i].maxFreq = 1;
        info[i].sumOfMax += x;
    }

    vector<vi> adj(n);
    for (int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v; u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vi answer(n);
    function<int(int, int)> dfs = [&](int u, int p) -> int {
        int root = u;
        for(int v : adj[u]){
            if(v == p) continue;
            root = merge(root, dfs(v, u));
        }
        
        answer[u] = info[root].sumOfMax;
        return root;
    };
    
    dfs(0, -1);
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