/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// Forest Queries II
// URL: https://cses.fi/problemset/task/1739
// Time: 5/27/2025, 6:48:42 PM
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


struct Fenwick2D {
    int n, m;
    vector<vi> bit;

    Fenwick2D(int _n, int _m) : n(_n), m(_m), bit(n + 1, vi(m + 1, 0)) {}

    void update(int x, int y, int val) {
        for (int i = x; i <= n; i += i & -i) 
            for (int j = y; j <= m; j += j & -j) 
                bit[i][j] += val;
    }

    int prefixSum(int x, int y){
        int res = 0;
        for (int i = x; i > 0; i -= i & -i) 
            for (int j = y; j > 0; j -= j & -j) 
                res += bit[i][j];        
        return res;
    }

    int rangeSum(int x1, int y1, int x2, int y2){
        return prefixSum(x2, y2)
             - prefixSum(x1 - 1, y2)
             - prefixSum(x2, y1 - 1)
             + prefixSum(x1 - 1, y1 - 1);
    }
};

void Ramez() {
    int n, q; cin >> n >> q;
    vector<vi> forest(n + 1, vi(n + 1));

    Fenwick2D t(n, n);

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            char c; cin >> c;
            if(c == '*') t.update(i, j, 1), forest[i][j] = 1;
        }
    }
    
    while(q--){
        int ops; cin >> ops;
        if(ops == 1){
            int y, x; cin >> y >> x;
            if(forest[y][x] == 0){
                t.update(y, x, 1);
                forest[y][x] = 1;
            } else {
                t.update(y, x, -1);
                forest[y][x] = 0;
            }
        } else {
            int y1, x1, y2, x2; 
            cin >> y1 >> x1 >> y2 >> x2;
            cout << t.rangeSum(y1, x1, y2, x2) << "\n";
        }
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