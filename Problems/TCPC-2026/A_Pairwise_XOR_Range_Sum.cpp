// A. Pairwise XOR Range Sum
// URL: https://codeforces.com/group/Rilx5irOux/contest/678837/problem/A
// Time: 4/18/2026, 1:22:27 AM
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

bool isSet (int x, int bit) {
    return x & (1 << bit);
}

void solve() {
    int n; cin >> n;
    vi a(n); cin >> a;
    
    int BIT_COUNT = 32;
    vector<vi> bit_sum(BIT_COUNT, vi(n, 0));
    
    for (int bit = 0; bit < BIT_COUNT; bit++) {
        for (int i = 0; i < n; i++) {
            if (isSet(a[i], bit)) {
                bit_sum[bit][i] = 1;
            }
            if(i) bit_sum[bit][i] += bit_sum[bit][i - 1];
        }
    }

    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        l--; r--;
        int total_cnt = r - l + 1;
        int sum = 0;
        for (int bit = 0; bit < BIT_COUNT; bit++) {
            int set_cnt = bit_sum[bit][r] - (l? bit_sum[bit][l - 1] : 0);
            int unset_cnt = total_cnt - set_cnt;
            sum += set_cnt * unset_cnt * (1 << bit);
        }
        cout << sum << "\n";
    }
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