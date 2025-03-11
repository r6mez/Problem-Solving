// -------------------- Ramez -------------------------
// سَأَحمِلُ روحي عَلى راحَتي    وَأُلقي بِها في مَهاوي الرَدى
// فَإِمّـا حَــيــاةٌ تُسِــرُّ الـصَديقَ    وَإِمّــا مَمــاتٌ يُغــيظُ العِــدى
// ----------------------------------------------------
// Contest: USACO 2017 January Contest, Silver
// Judge: USACO
// URL: https://usaco.org/index.php?page=viewproblem2&cpid=691
// Memory Limit: 256
// Time Limit: 4000
// Start: Tue Aug 27 20:27:27 2024
#ifdef ALGOAT
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif
#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vvi vector<vi>
#define vll vector<long long>
#define vvll vector<vll>
#define vs vector<string>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;
struct SegTree;
const int MOD = 1000000007;
#define all(v) v.begin(), v.end()
#define makeUnique(v) v.erase(unique(all(v)), v.end())
vector<vll> prefixSum2D(vector<vll> &a);
ll sumOfSquare(int x1, int y1, int x2, int y2, vector<vll> &a);
template <typename T> ostream &operator<<(ostream &os, const vector<T> &v);
template <typename T> istream &operator>>(istream &is, vector<T> &v);
void FastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
}
void UseFile() {
  freopen("hps.in", "r", stdin);
  freopen("hps.out", "w", stdout);
}

int main() {
  UseFile();
  FastIO();
  int t = 1;
  // cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vi a(n + 1), b(n + 1), c(n + 1);
    for (int i = 1; i <= n; i++) {
      char x;
      cin >> x;
      if (x == 'H')
        a[i] = 1;
      if (x == 'P')
        b[i] = 1;
      if (x == 'S')
        c[i] = 1;
    }

    partial_sum(all(a), a.begin());
    partial_sum(all(b), b.begin());
    partial_sum(all(c), c.begin());

    int maxAns = 0;

    debug(a);
    debug(b);
    debug(c);
    
    for (int i = 1; i <= n; i++) {
        int largestFirstHalf = max({a[i], b[i], c[i]});
        int largestSecondHalf = max({a[n] - a[i], b[n] - b[i], c[n] - c[i]});
        maxAns = max(maxAns, largestFirstHalf+largestSecondHalf);
    }
    
    cout << maxAns << "\n";
  }
  return 0;
}

/*
NOTES:
0 1 2 3 4 5 

*/

class SegmentTree {
public:
  int size;
  vector<ll> sums, mins, maxs;

  SegmentTree(int n) {
    size = 1;
    while (size < n)
      size *= 2;
    sums.assign(2 * size, 0LL);
    mins.assign(2 * size, LLONG_MAX);
    maxs.assign(2 * size, LLONG_MIN);
  }

  void build(const vi &a) { build(a, 0, 0, size); }

  void update(int i, int v) { update(i, v, 0, 0, size); }

  ll sumSeg(int l, int r) { return sumSeg(l, r, 0, 0, size); }

  ll minSeg(int l, int r) { return minSeg(l, r, 0, 0, size); }

  ll maxSeg(int l, int r) { return maxSeg(l, r, 0, 0, size); }

  ll firstElementAtLeastX(int x) { return firstElementAtLeastX(x, 0, 0, size); }

private:
  void build(const vi &a, int x, int lx, int rx) {
    if (rx - lx == 1) {
      if (lx < (int)a.size()) {
        sums[x] = a[lx];
        mins[x] = a[lx];
        maxs[x] = a[lx];
      }
      return;
    }
    int mid = (lx + rx) / 2;
    build(a, 2 * x + 1, lx, mid);
    build(a, 2 * x + 2, mid, rx);
    sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
    mins[x] = min(mins[2 * x + 1], mins[2 * x + 2]);
    maxs[x] = max(maxs[2 * x + 1], maxs[2 * x + 2]);
  }

  void update(int i, int v, int x, int lx, int rx) {
    if (rx - lx == 1) {
      sums[x] = v;
      mins[x] = v;
      maxs[x] = v;
      return;
    }
    int mid = (lx + rx) / 2;
    if (i < mid) {
      update(i, v, 2 * x + 1, lx, mid);
    } else {
      update(i, v, 2 * x + 2, mid, rx);
    }
    sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
    mins[x] = min(mins[2 * x + 1], mins[2 * x + 2]);
    maxs[x] = max(maxs[2 * x + 1], maxs[2 * x + 2]);
  }

  ll sumSeg(int l, int r, int x, int lx, int rx) {
    if (lx >= r || l >= rx)
      return 0;
    if (lx >= l && rx <= r)
      return sums[x];
    int mid = (lx + rx) / 2;
    ll left = sumSeg(l, r, 2 * x + 1, lx, mid);
    ll right = sumSeg(l, r, 2 * x + 2, mid, rx);
    return left + right;
  }

  ll minSeg(int l, int r, int x, int lx, int rx) {
    if (lx >= r || l >= rx)
      return LLONG_MAX;
    if (lx >= l && rx <= r)
      return mins[x];
    int mid = (lx + rx) / 2;
    ll left = minSeg(l, r, 2 * x + 1, lx, mid);
    ll right = minSeg(l, r, 2 * x + 2, mid, rx);
    return min(left, right);
  }

  ll maxSeg(int l, int r, int x, int lx, int rx) {
    if (lx >= r || l >= rx)
      return LLONG_MIN;
    if (lx >= l && rx <= r)
      return maxs[x];
    int mid = (lx + rx) / 2;
    ll left = maxSeg(l, r, 2 * x + 1, lx, mid);
    ll right = maxSeg(l, r, 2 * x + 2, mid, rx);
    return max(left, right);
  }

  ll firstElementAtLeastX(int x, int currentNode, int l, int r) {
    if (maxs[currentNode] < x) {
      return -1;
    }

    if (r - l == 1) { // we're in the bottom of the tree
      return l;
    }

    int mid = (l + r) / 2;
    int res = firstElementAtLeastX(x, 2 * currentNode + 1, l, mid);
    if (res == -1) {
      res = firstElementAtLeastX(x, 2 * currentNode + 2, mid, r);
    }
    return res;
  }
};

template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) {
  for (const auto &i : v)
    os << i << ' ';
  return os;
}

template <typename T> istream &operator>>(istream &is, vector<T> &v) {
  for (auto &i : v)
    is >> i;
  return is;
}

vector<vll> prefixSum2D(vector<vll> &a) {
  vector<vll> b(a.size(), vll(a[0].size()));
  for (int i = 0; i < a.size(); i++) {
    partial_sum(all(a[i]), b[i].begin());
  }
  for (int i = 0; i < a[0].size(); i++) {
    for (int j = 1; j < a.size(); j++) {
      b[j][i] += b[j - 1][i];
    }
  }
  return b;
}

ll sumOfSquare(int x1, int y1, int x2, int y2, vector<vll> &a) {
  return (a[x2][y2] - a[x1 - 1][y2] - a[x2][y1 - 1]) + a[x1 - 1][y1 - 1];
}
