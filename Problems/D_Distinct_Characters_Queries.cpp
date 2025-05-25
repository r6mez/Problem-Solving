/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// D. Distinct Characters Queries
// URL: https://codeforces.com/problemset/problem/1234/D
// Time: 5/25/2025, 8:54:59 PM
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
    string s; cin >> s;
    int n = s.size();
    
    vector<FenwickPURQ> f(26, FenwickPURQ(n + 1));
 
    for (int i = 0; i < n; i++){
        int c = s[i] - 'a';
        f[c].update(i + 1, 1);
    }
    

    int q; cin >> q;
    while(q--){
        int ops; cin >> ops;
        if(ops == 1){
            int pos; char c; cin >> pos >> c;
            int prev = s[pos - 1] - 'a';
            int curr = c - 'a';
            f[prev].update(pos, -1);
            f[curr].update(pos, 1);
            s[pos - 1] = c;
        } else {
            int l, r; cin >> l >> r;
            int cnt = 0;
            for (int i = 0; i < 26; i++){
                cnt += (f[i].rangeQuery(l, r) > 0);
            }
            cout << cnt << "\n";
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