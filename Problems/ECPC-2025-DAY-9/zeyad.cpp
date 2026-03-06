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

int dp[100003][5];
int rec(int tu, int idx) {
    ll &ret = dp[idx][tu];
    if (ret != -1) return ret;
    
}
void solve() {
    int n; cin >> n;
    vector<int> a(n + 3);
    map<int, vector<int>> mp;
    for (int i = 1; i <= n; i++){
         cin >> a[i];
         mp[a[i]].push_back(i);         
        }

}

/*

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}