// E. Nearly Shortest Repeating Substring
// URL: https://codeforces.com/problemset/problem/1950/E
// Time: 3/31/2026, 12:01:43 AM
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
  for (int i = 1; i <= n; i++) {
    if (n % i == 0) {
      int satisfy = 2;
      for (int j = 0; j < i; j++) {
        for (int k = j + i; k < n; k += i) {
          if (s[k] != s[j]) {
            satisfy--;
          }
        }
      }
      if (satisfy > 0) { 
        cout << i << endl;
        return;
      }
      satisfy = 2;
      for (int j = n - i; j < n; j++) {
        for (int k = j - i; k >= 0; k -= i) {
          if (s[k] != s[j]) {
            satisfy--;
          }
        }
      }
      if (satisfy > 0) {
        cout << i << endl;
        return;
      }
    }
  }
}

/*

*/

signed main() {
  // UseFile();
  FastIO();
  int t = 1;
  cin >> t;
  while (t--)
    solve();
}