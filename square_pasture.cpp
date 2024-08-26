// -------------------- Ramez -------------------------
// سَأَحمِلُ روحي عَلى راحَتي    وَأُلقي بِها في مَهاوي الرَدى
// فَإِمّـا حَــيــاةٌ تُسِــرُّ الـصَديقَ    وَإِمّــا مَمــاتٌ يُغــيظُ العِــدى
// ----------------------------------------------------
// Contest: USACO 2016 December Contest, Bronze
// Judge: USACO
// URL: https://usaco.org/index.php?page=viewproblem2&cpid=663
// Memory Limit: 256
// Time Limit: 4000
// Start: Sun Aug 25 15:23:32 2024
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
#ifdef YaWaga3Eldebug
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif
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
  freopen("square.in", "r", stdin);
  freopen("square.out", "w", stdout);
}

int main() {
  UseFile();
  FastIO();
  int t = 1;
  // cin >> t;
  while (t--) {
    int x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    int squareSide = max(max(x2, x4) - min(x1, x3), max(y2, y4) - min(y1, y3));
    cout << squareSide * squareSide;
  }
  return 0;
}
