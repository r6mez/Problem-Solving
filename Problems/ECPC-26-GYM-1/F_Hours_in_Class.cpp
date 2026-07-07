// F. Hours in Class
// URL: https://codeforces.com/group/zZYq310uLQ/contest/699485/problem/F
// Time: 6/25/2026, 1:44:34 PM
#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <vector>
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

int NMAX = 1e6;
vi spf(NMAX + 1, 1);
int t, x;

const int inf = 1e9;

struct Node {
  Node *l = 0, *r = 0;
  int lo, hi;
  int mx = -inf, mn = inf, sum = 0;
  int la = 1, lb = 0;

  Node(int lo, int hi) : lo(lo), hi(hi) {}

  Node(vector<int> &v, int lo, int hi) : lo(lo), hi(hi) {
    if (lo + 1 < hi) {
      int mid = lo + (hi - lo) / 2;
      l = new Node(v, lo, mid);
      r = new Node(v, mid, hi);
      mx = max(l->mx, r->mx);
      mn = min(l->mn, r->mn);
      sum = l->sum + r->sum;
    } else {
      mx = mn = sum = v[lo];
    }
  }

  void push() {
    if (!l) {
      int mid = lo + (hi - lo) / 2;
      l = new Node(lo, mid);
      r = new Node(mid, hi);
    }
    if (la != 1 || lb != 0) {
      l->apply(la, lb);
      r->apply(la, lb);
      la = 1;
      lb = 0;
    }
  }

  void apply(int a, int b) {
    int t1 = mx * a + b;
    int t2 = mn * a + b;

    mx = max(t1, t2);
    mn = min(t2, t1);
    sum = sum * a + b * (hi - lo);

    la = la * a;
    lb = lb * a + b;
  }

  void update(int L, int R, int a, int b) {
    if (R <= lo || hi <= L)
      return;
    if (L <= lo && hi <= R) {
      apply(a, b);
    } else {
      push();
      l->update(L, R, a, b);
      r->update(L, R, a, b);
      mx = max(l->mx, r->mx);
      mn = min(l->mn, r->mn);
      sum = l->sum + r->sum;
    }
  }

  int query(int L, int R) {
    if (R <= lo || hi <= L)
      return -inf;
    if (L <= lo && hi <= R)
      return mx;
    push();
    return max(l->query(L, R), r->query(L, R));
  }

  void set(int L, int R, int x) { update(L, R, 0, x); }
  void add(int L, int R, int x) { update(L, R, 1, x); }
  void mult(int L, int R, int x) { update(L, R, x, 0); }
};
// 1
// t1
//  t2
// t3
vi v(1e5);
Node *vprime = new Node(v, 0, size(v));
map<int, int> primes;
map<int, int> ptoind;
int limit = 100000;
void solve() {
  cin >> t >> x;
  if (t == 1) { // log
    while (x > 1) {
      int ind = ptoind[spf[x]];
      int q = vprime->query(ind, ind + 1);

      vprime->set(ind, ind + 1, 0);
      if (q > 0) {
        if (primes[spf[x]] > limit / q) {
          primes[spf[x]] = limit;
        } else {
          primes[spf[x]] *= q;
        }
      }
      primes[spf[x]]++;
      x /= spf[x];
    }
  }
  if (t == 2) { // size(primes)
    vprime->add(1, v.size() - 1, x);
  }
  if (t == 3) { // log

    map<int, int> pa;

    while (x > 1) {
      pa[spf[x]]++;
      x /= spf[x];
    }
    for (auto &[a, b] : pa) {
      int ind = ptoind[a];
      int q = vprime->query(ind, ind + 1);
      vprime->set(ind, ind + 1, 0);
      if (q > 0) {
        if (primes[a] > limit / q) {
          primes[a] = limit;
        } else {
          primes[a] *= q;
        }
      }

      if (primes[a] < b) {
        cout << "No\n";
        return;
      }
    }
    cout << "Yes\n";
  }
}

/*

*/

signed main() {
  // UseFile();
  FastIO();
  int t = 1;

  spf[0] = 0;
  spf[1] = 1;
  for (int i = 2; i <= NMAX; ++i)
    if (spf[i] == 1)
      for (int j = i; j <= NMAX; j += i)
        if (spf[j] == 1)
          spf[j] = i;
  int ind = 0;
  map<int, int> pr;

  for (auto i : spf) {
    pr[i] = 1;
  }
  for (auto [a, b] : pr) {
    ptoind[a] = ind++;
  }
  cin >> t;
  while (t--)
    solve();
}