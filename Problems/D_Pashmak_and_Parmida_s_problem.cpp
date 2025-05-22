/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// D. Pashmak and Parmida's problem
// URL: https://codeforces.com/contest/459/problem/D
// Time: 5/22/2025, 8:46:50 PM
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
    int n; cin >> n;
    vi a(n); cin >> a;
    
    vi pre(n);
    map<int, int> freq;
    for (int i = 0; i < n; i++){
        freq[a[i]]++;
        pre[i] = freq[a[i]];
    }
    
    freq.clear();

    vi suff(n);
    for (int i = n - 1; i >= 0; i--){
        freq[a[i]]++;
        suff[i] = freq[a[i]];        
    }

    // cout << pre << "\n" << suff << "\n";

    int size = 1e6 + 5;
    FenwickPURQ tree(size);
    int cnt = 0;

    for (int i = n - 1; i >= 0; i--){
        if(pre[i] != 1) cnt += tree.rangeQuery(1, pre[i] - 1);
        tree.update(suff[i], 1);
    }
    
    cout << cnt;
}


/*
NOTES:
for each pre[i]
I want to find number of elemenets 
smaller than pre[i] in the range i + 1 ... n  

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}