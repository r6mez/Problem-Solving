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


struct FenwickPURQ {
    int n;
    vi f;

    FenwickPURQ(int size) : n(size), f(n + 1, 0) {}

    void add(int idx, int val) {
        for (; idx <= n; idx += idx & -idx) f[idx] += val;
    }
    
    int prefix(int idx) {
        int res = 0;
        for (; idx > 0; idx -= idx & -idx) res += f[idx];
        return res;
    }
    
    int rangeQuery(int l, int r) {
        return prefix(r) - prefix(l - 1);
    }
};

int n;
vector<vi> G;
vi color;
vi in_t, out_t;
int timer;

void dfs(int u, int p) {
    in_t[u] = ++timer;
    for (int v : G[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
    out_t[u] = ++timer;
}

void Ramez() {
    cin >> n;
    color.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> color[i];
    G.assign(n + 1, vi());
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    in_t.assign(n + 1, 0);
    out_t.assign(n + 1, 0);
    timer = 0;
    dfs(1, 0);

    int N2 = 2 * n;
    vi x(N2 + 1);
    for (int i = 1; i <= n; i++) {
        x[in_t[i]] = color[i];
        x[out_t[i]] = color[i];
    }

    vi ptr(N2 + 1, 0);
    unordered_map<int, int> last;
    last.reserve(N2 * 2);
    for (int i = N2; i >= 1; i--) {
        auto it = last.find(x[i]);
        if (it != last.end()) ptr[i] = it->second;
        last[x[i]] = i;
    }

    FenwickPURQ BIT(N2);
    unordered_set<int> seen;
    seen.reserve(N2 * 2);
    for (int i = 1; i <= N2; i++) {
        if (seen.insert(x[i]).second) {
            BIT.add(i, 1);
        }
    }

    struct Query { int L, R, idx; };
    vector<Query> queries;
    queries.reserve(n);
    for (int i = 1; i <= n; i++) {
        queries.push_back({in_t[i], out_t[i], i});
    }
    sort(all(queries), [](auto &a, auto &b){ return a.L < b.L; });

    vi ans(n + 1);
    int l = 1;
    for (auto &q : queries) {
        while (l < q.L) {
            if (ptr[l] != 0) BIT.add(ptr[l], 1);
            l++;
        }
        ans[q.idx] = BIT.rangeQuery(q.L, q.R);
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << (i == n ? '\n' : ' ');
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