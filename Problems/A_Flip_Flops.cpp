// A. Flip Flops
// URL: https://codeforces.com/contest/2209/problem/A
// Time: 3/26/2026, 5:28:36 PM
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define int         long long
#define vi          vector<int>
#define pii         pair<int, int>
#define all(v)      v.begin(), v.end()
#define finish(s)   { cout << s << "\n"; return; }
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { cin.tie(nullptr)->sync_with_stdio(false); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007, INF = 2e18;

void solve() {
    int n, c, k; cin >> n >> c >> k;
    multiset<int> s;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        s.insert(x);
    }

    while(!s.empty()) {
        auto x = lower_bound(all(s), c);
        if (x == s.begin() && *x > c) { // all bigger
            break;
        }

        if(x == s.end() || *x > c) { 
            x--;
        } 

        int add = min(k, c - *x);
        c += *x + add;
        k -= add;
        s.erase(x);
    }

    cout << c << "\n";
}

/*

*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t; 
    while (t--) solve();
}