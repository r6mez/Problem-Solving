// K. Keyboard Chaos
// URL: https://codeforces.com/group/zZYq310uLQ/contest/706234/problem/K
// Time: 7/26/2026, 3:46:35 PM
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
    int n, e; cin >> n >> e;
    vi freq(e);
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        int c = s[0] - 'a';
        if(freq[c] == -1) continue;
        int j = 0;
        while(j < s.size() && s[j] == s[0]) freq[c]++, j++;
        if(j == s.size()) freq[c] = -1;
    }

    int min_sum = INT_MAX, min_idx;
    for (int i = 0; i < e; i++) {
        if(freq[i] != -1 && min_sum > freq[i]) {
            min_sum = freq[i];
            min_idx = i;
        }
    }

    if(min_sum == INT_MAX) cout << "NO";
    else cout << string(min_sum + 1, char('a' + min_idx));
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