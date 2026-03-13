// D. Binary Lightning
// URL: https://codeforces.com/group/4afEIuSpfa/contest/676953/problem/D
// Time: 3/12/2026, 8:01:32 PM
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

vi BINs;
int n;

void generate (int x) {
    BINs.push_back(x);
    if(x * 10 + 0 <= n) generate(x * 10 + 0);
    if(x * 10 + 1 <= n) generate(x * 10 + 1);
}

void solve() {
    cin >> n;
    generate (1);
    cout << BINs.size();
}

/*

*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) solve();
}