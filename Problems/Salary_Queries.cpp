/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// Salary Queries
// URL: https://cses.fi/problemset/task/1144/
// Time: 5/25/2025, 7:39:02 PM
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

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void Ramez() {
    int n, q; cin >> n >> q;
    vi a(n + 1); 

    Tree<pii> t; 
    // we didn't use normal set because we can't get the range from it.

    for (int i = 1; i <= n; i++){
        cin >> a[i];
        t.insert({a[i], i});
    }
    
    while(q--){
        char c; cin >> c;
        if(c == '!'){
            int k, x; cin >> k >> x;
            t.erase({a[k], k});
            a[k] = x;
            t.insert({a[k], k});
        } else {
            int a, b; cin >> a >> b;
            // order_of_key return the index of the lower bound.
            int cnt = t.order_of_key({b, MOD}) - t.order_of_key({a - 1, MOD});
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