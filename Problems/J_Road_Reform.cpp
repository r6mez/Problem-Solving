/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// J. Road Reform
// URL: https://codeforces.com/contest/1468/problem/J
// Time: 6/29/2025, 6:12:18 PM
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

struct DSU {
    vector<int> parent, size;
    int count; // of component

    DSU(int n) : parent(n + 1), size(n + 1, 1), count(n) { iota(all(parent), 0); }

    int find(int i) { return (parent[i] == i ? i : (parent[i] = find(parent[i]))); }

    bool same(int i, int j) { return find(i) == find(j); }

    int getSize(int i) { return size[find(i)]; }

    bool merge(int i, int j) {
        if ((i = find(i)) == (j = find(j))) return false;
        else --count;
        if (size[i] > size[j]) swap(i, j);
        parent[i] = j;
        size[j] += size[i];
        return true;
    }
};

void Ramez() {
    int n, m, k; cin >> n >> m >> k;

    vector<array<int, 3>> edges(m);
    for (auto& [w, u, v] : edges) cin >> u >> v >> w;

    sort(all(edges));

    DSU dsu(n);
    int ans = 0, added = 0;
    bool can = false;
    for (auto& [w, u, v] : edges) {
        if (dsu.merge(u, v)) {
            added++;
            ans += max(0LL, w - k);
        }

        if (w < k && added == n - 1) {
            ans = k - w;
            can = true;
        } else if (can) {
            ans = min(ans, abs(k - w));
        }
    }

    cout << ans << "\n";
}

/*
NOTES:

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}