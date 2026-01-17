// D1. Sub-RBS (Easy Version)
// URL: https://codeforces.com/contest/2191/problem/D1
// Time: 1/17/2026, 9:52:09 PM
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
    string s; cin >> s;
    string t = "";

    vector<int> nextOpening(n + 1, n + 1);
    vector<int> openingsCnt(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '(') nextOpening[i] = i;
        else nextOpening[i] = nextOpening[i + 1];
        if (s[i] == '(') openingsCnt[i] += 1;
        openingsCnt[i] += openingsCnt[i + 1];
    }

    int ans = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == ')' and nextOpening[i] <= n) {
            int removed = nextOpening[i] - i;
            if (openingsCnt[nextOpening[i] + 1] >= removed) {
                ans = max(ans, n - 2 * removed);
            }
        }
    }

    cout << ans << '\n';
}

/*
if exist, find the longest subsequence t of string s that contains
let i be the first position where s[i] != t[i] then s[i] = ) and t[i] = (
both s and t are regular bracket sequences

(()(()))
((())) i = 3 first differ
() not valid
(()) not valid
(()()) not valid

(())()
() not valid
*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}