/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// Distinct Values Queries
// URL: https://cses.fi/problemset/task/1734
// Time: 5/25/2025, 8:05:27 PM
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
    FenwickPURQ(int _n) : n(_n), f(n + 1, 0) {}

    // update
    void update(int idx, int val) {
        for (; idx <= n; idx += idx & -idx)
            f[idx] += val;
    }

    // queary
    int prefix(int idx) {
        int res = 0;
        for (; idx > 0; idx -= idx & -idx)
            res += f[idx];
        return res;
    }

    int rangeQuery(int l, int r) {
        return prefix(r) - prefix(l - 1);
    }
};

void Ramez() {
    int n, q; cin >> n >> q;
    vi a(n + 1); 
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    
    struct query {
        int a, b, idx;
    };

    vector<query> Q(q);

    for (int i = 0; i < q; i++){
        cin >> Q[i].a >> Q[i].b;
        Q[i].idx = i;
    }

    sort(all(Q), [&](query &x, const query &y){ return x.b < y.b; });

    FenwickPURQ t(n);
    map<int, int> last;
    vi ans(q); 
    
    int r = 0;
    for(auto &[x, y, idx] : Q){
        while(r < y){
            r++;
            int v = a[r];
            if(last.count(v)){
                t.update(last[v], -1);
            }
            t.update(r, 1);
            last[v] = r;
        }

        ans[idx] = t.rangeQuery(x, y);
    }

    for (int i = 0; i < q; i++){
        cout << ans[i] << "\n";
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