// D. The Zigzag Robot
// URL: https://codeforces.com/group/Rilx5irOux/contest/686782/problem/D
// Time: 5/25/2026, 3:07:19 PM
#include <bits/stdc++.h>
#include <functional>
#include <iostream>
#include <map>
using namespace std;
#define int long long
#define vi vector<int>
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define finish(s)                                                              \
  {                                                                            \
    cout << s << "\n";                                                         \
    return;                                                                    \
  }
template <typename T> ostream &operator<<(ostream &os, vector<T> &v) {
  for (auto &i : v)
    os << i << ' ';
  return os;
}
template <typename T> istream &operator>>(istream &is, vector<T> &v) {
  for (auto &i : v)
    is >> i;
  return is;
}
void FastIO() { cin.tie(nullptr)->sync_with_stdio(false); }
void UseFile() {
  freopen("file.in", "r", stdin);
  freopen("file.out", "w", stdout);
}
const int MOD = 1000000007, INF = 2e18;

int dx[] = {
    -1,
    1,
    0,
    0,
};
int dy[] = {
    0,
    0,
    -1,
    1,
};
char dr[] = {'U', 'D', 'L', 'R'};

void solve() {
  int n;
  cin >> n;
  int m = 2;
  vector<string> s(m);
  for (string &ezz : s)
    cin >> ezz;
  int f = 0;
  for (auto i : s) {
    for (auto j : i) {
      if (j != '#')
        f = 1;
    }
  }
  if (f == 0) {
    cout << 0 << "\n";
    return;
  }
  int answer = 1;
  vi pp;
  pp.push_back(-2);
  for (int i = 0; i < n; i++) {
    if (s[0][i] == '#' || s[1][i] == '#') {

      int su = (s[0][i] == '#') - (s[1][i] == '#');
      pp.push_back(su - 2);
    } else {
      if (pp.empty() || pp.back() <= 0)
        pp.push_back(1);
      else
        pp.back()++;
    }
  }
  pp.push_back(-2);

  for (auto i : pp) {
   // cout << i << " ";
  }
   // cout << "\n";
  for (int i = 0; i + 2 < pp.size(); i++) {
    int x;
    if (pp[i + 1] > 0 && pp[i] == pp[i + 2] && pp[i] == -2)
      x = 0;

    else if (pp[i + 1] > 0 && pp[i] != pp[i + 2] &&
             (pp[i] == -2 || pp[i + 2] == -2))
      x = 1;

    else if (pp[i + 1] > 0 && ((pp[i + 1] & 1 && pp[i] != pp[i + 2]) ||
                               (!(pp[i + 1] & 1) && pp[i] == pp[i + 2])))
      x = 2;
    else
      x = 1;
    // cout << x << "SAD\n";
    if (pp[i + 1] > 0)
      answer = max(answer, pp[i + 1] * 2 + x);
    else if (pp[i] == pp[i + 1] && !(pp[i] == -2 || pp[i + 2] == -2)) {
      answer = max(answer, 3LL);
    }
  }

  if (pp[1] == pp[2] && !(pp[1] == -2 || pp[2] == -2)) {
    answer = max(answer, 2LL);
  }
  cout << answer << "\n";
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