/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// Planets Queries I
// URL: https://cses.fi/problemset/task/1750
// Time: 5/8/2025, 8:45:09 PM
#include <bits/stdc++.h>
using namespace std;
// #define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007;

class Tree {
private:
    int MAXPOW;
    vector<vi> up; // up[n][k] = 2^k-th ancestor of node n

public:
    Tree(int n, const vi &parents) {
        MAXPOW = ceil(log2(1e9 + 5));
        up.assign(n+1, vi(MAXPOW + 1, -1));

        for (int v = 1; v <= n; ++v) {
            up[v][0] = parents[v - 1]; 
        }

        for (int k = 1; k <= MAXPOW; ++k) {
            for (int v = 1; v <= n; ++v) {
                int m = up[v][k-1];
                if (m != -1) {
                    up[v][k] = up[m][k-1];
                }
            }
        }
    }

    int kth_parent(int n, int k) {
        for (int bit = 0; bit <= MAXPOW && n != -1; ++bit) {
            if (k & (1 << bit)) {
                n = up[n][bit];
            }
        }
        return n;
    }
};


void Ramez() {
    int n, q; cin >> n >> q;
    vi parents(n); cin >> parents;

    Tree t(n, parents);

    while (q--){
        int node, k; cin >> node >> k;
        cout << t.kth_parent(node, k) << "\n";
    }
}

/*
NOTES:
1 2
*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}