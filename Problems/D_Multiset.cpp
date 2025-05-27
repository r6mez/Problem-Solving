/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// D. Multiset
// URL: https://codeforces.com/contest/1354/problem/D
// Time: 5/27/2025, 4:50:11 PM
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

struct FenwickPURQ {    
    int n;
    vi f;

    void add(int idx, int val) {
        for (; idx <= n; idx += idx & -idx)
        f[idx] += val;
    }
    
    int prefix(int idx) {
        int res = 0;
        for (; idx > 0; idx -= idx & -idx)
        res += f[idx];
        return res;
    }
    
    FenwickPURQ(int size) : n(size), f(n + 1, 0) {}

    int rangeQuery(int l, int r) {
        return prefix(r) - prefix(l - 1);
    }

    int lower_bound(int v){
        int sum = 0, pos = 0;
        for(int i = ceil(log2(n)); i >= 0; i--){
            int nextPos = pos + (1 << i);
            if(pos + (1 << i) < n && sum + f[nextPos] < v){
                sum += f[nextPos];
                pos = nextPos;
            }		
        }
        return pos + 1;
    }
};

void Ramez() {
    int n, q; cin >> n >> q;
    FenwickPURQ t(n + 1);
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        t.add(x, 1);
    }

    while(q--){
        int k; cin >> k;
        if(k > 0){
            t.add(k, 1);
        } else {
            k = -k;
            int num = t.lower_bound(k);
            t.add(num, -1);
        }
    }

    int ans = t.rangeQuery(1, n);

    if(!ans){
        cout << 0;
        return;
    }

    cout << t.lower_bound(1);
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