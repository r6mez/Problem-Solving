// G. Fibonacci Sequence
// URL: https://codeforces.com/group/Rilx5irOux/contest/643069/problem/G
// Time: 5/3/2026, 9:32:21 PM
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
    int n; cin >> n;
    if (n <= 2) {
        cout << "0\n\n";
        return;
    }
    int len = n - 1;
    string ops(len, ' ');
    for (int i = 0; i < len; i++) {
        ops[i] = (i % 2 == 0) ? 'F' : 'B';
    }
    if (n % 2 == 0) {
        ops[len - 1] = 'B';
    }
    cout << len << "\n" << ops << "\n";
}

/*

0 1 F
1 1 B
1 2 F
3 2
*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}