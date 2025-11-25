/*
    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⣀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠳⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⣀⡴⢧⣀⠀⠀⣀⣠⠤⠤⠤⠤⣄⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠘⠏⢀⡴⠊⠁⠀⠀⠀⠀⠀⠀⠈⠙⠦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⣰⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⢶⣶⣒⣶⠦⣤⣀⠀
⠀⠀⠀⠀⠀⠀⢀⣰⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣟⠲⡌⠙⢦⠈⢧
⠀⠀⠀⣠⢴⡾⢟⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⡴⢃⡠⠋⣠⠋
⠐⠀⠞⣱⠋⢰⠁⢿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣠⠤⢖⣋⡥⢖⣫⠔⠋⠀⠀
⠈⠠⡀⠹⢤⣈⣙⠚⠶⠤⠤⠤⠴⠶⣒⣒⣚⣩⠭⢵⣒⣻⠭⢖⠏⠁⢀⣀⠀⠀⠀
⠠⠀⠈⠓⠒⠦⠭⠭⠭⣭⠭⠭⠭⠭⠿⠓⠒⠛⠉⠉⠀⠀⣠⠏⠀⠀⠘⠞⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠓⢤⣀⠀⠀⠀⠀⠀⠀⣀⡤⠞⠁⠀⣰⣆⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠘⠿⠀⠀⠀⠀⠀⠈⠉⠙⠒⠒⠛⠉⠁⠀⠀⠀⠉⢳⡞⠉⠀⠀⠀⠀⠀

*/
// F. Rae Taylor and Trees (hard version)
// URL: https://codeforces.com/contest/2171/problem/F
// Time: 11/20/2025, 5:36:32 PM
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

struct DSU {
    vector<int> parent, size, minE, maxE;
    int count; // of component

    DSU(int n) : parent(n + 1), size(n + 1, 1), count(n), minE(n + 1), maxE(n + 1) { iota(all(parent), 0LL); minE = parent; maxE = parent; }

    int find(int i) { return (parent[i] == i ? i : (parent[i] = find(parent[i]))); }

    bool same(int i, int j) { return find(i) == find(j); }

    int getSize(int i) { return size[find(i)]; }

    int merge(int i, int j) {
        if ((i = find(i)) == (j = find(j))) return -1;
        else --count;
        if (size[i] > size[j]) swap(i, j);
        parent[i] = j;
        size[j] += size[i];
        minE[j] = min(minE[i], minE[j]);
        maxE[j] = max(maxE[i], maxE[j]);
        return j;
    }
};

void solve() {
    int n; cin >> n;
    vi a(n); cin >> a;

    vi pre(n), suf(n), pos(n + 1);
    pre[0] = a[0];
    suf[n - 1] = a[n - 1];

    for (int i = 0; i < n; i++){
        pos[a[i]] = i;
    }
    
    for (int i = 1; i < n; i++) {
        pre[i] = min(pre[i - 1], a[i]);
    }

    for (int i = n - 2; i >= 0; i--) {
        suf[i] = max(suf[i + 1], a[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        if (pre[i] > suf[i + 1]) finish("No");
    }

    DSU d(n);
    vector<pii> edges;
    vector<int> st;
    for (int x : a) {
        while (!st.empty() && st.back() < x) {
            int y = st.back(); st.pop_back();
            edges.emplace_back(y, x);
            d.merge(y, x);
        }
        st.push_back(x);
    }

    vector<int> roots;
    for (int x : a) {
        int r = d.find(x);
        if (roots.empty() || roots.back() != r) roots.push_back(r);
    }

    // cout << "roots: " << roots << "\n";

    for (int i = 0; i < roots.size() - 1; ++i) {
        int Lroot = d.find(roots[i]), Rroot = d.find(roots[i+1]);
        if (Lroot == Rroot) continue; 
        int minL = d.minE[Lroot], maxR = d.maxE[Rroot]; 
        edges.emplace_back(minL, maxR);
        d.merge(minL, maxR);
    }

    cout << "Yes\n";
    for (auto& e : edges) cout << e.first << ' ' << e.second << '\n';
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