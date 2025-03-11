/*
"You’ve changed so much Thorfinn,
that anger in your eyes is gone, i’m glad"
*/
// Contest: Sheet #4 (Strings)
// Judge: Codeforces
// URL: https://codeforces.com/group/MWSDmqGsZm/contest/219856/problem/O
// Memory Limit: 4
// Time Limit: 7000
// Start: Sat 02 Nov 2024 03:46:25 PM EET 
#ifdef RAMEZ
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif
#include <bits/stdc++.h>
#define ll   long long
#define ull  unsigned ll
#define vi   vector<int>
#define vvi  vector<vi>
#define vll  vector<ll>
#define vvll vector<vll>
#define vs   vector<string>
#define pii  pair<int, int>
#define pll  pair<ll, ll>
using namespace std;

void Ramez(){
  int n; cin >> n;
  int a[200] = {0,};
  for (int i = 0; i < n; i++) {
    char c; cin >> c;
    a[c]++;
  }

  for (int i = 'a'; i <= 'z'; i++) {
    for (int j = 0; j < a[i]; j++) {
      cout << char(i);
    }
  }
}

void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }

int main() {
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}



