/*
    One day, I'm gonna grow wings
*/
// B. Fun Permutation
// URL: https://codeforces.com/contest/2137/problem/B
// Time: 9/7/2025, 5:51:02 PM
#include <bits/stdc++.h>
using namespace std;
#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { cin.tie(nullptr)->sync_with_stdio(false); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007;

void solve() {
    int n; cin >> n;
    vi p(n); cin >> p;
    vi q; for(int x : p) q.push_back(n + 1 - x);
    cout << q << "\n";
}

/*
6 7 1 5 4 3 2
3 2 8 4 5 6 7
1 

*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}