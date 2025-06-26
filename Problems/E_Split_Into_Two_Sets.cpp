/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// E. Split Into Two Sets
// URL: https://codeforces.com/problemset/problem/1702/E
// Time: 6/20/2025, 9:14:16 PM
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
    vector<vi> adj(n);

    vi vis(n), freq(n, 0);
    bool flag = true, cycleflag = false;
    int nodesum = 0;

    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        freq[a]++;
        freq[b]++;
    }

    function<void(int)> dfs = [&](int node) -> void {
        vis[node] = 1;
        nodesum++;
        for (auto x : adj[node]) {
            if (vis[x] == 1) cycleflag = true;
            else if (!vis[x]) dfs(x);
        }
        vis[node] = 2;
    };


    for (int i = 0; i < n; i++) {
        if (freq[i] > 2) {
            cout << "NO\n";
            return;
        }
        else {
            nodesum = 0;
            if (!vis[i]) {
                dfs(i);
                if (cycleflag && nodesum % 2 == 1) {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }

    cout << "YES\n";
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