/*
"You’ve changed so much Thorfinn,
that anger in your eyes is gone, i’m glad"
*/
// Contest: Sheet #4 (Strings)
// Judge: Codeforces
// URL: https://codeforces.com/group/MWSDmqGsZm/contest/219856/problem/P
// Memory Limit: 256
// Time Limit: 1000
// Start: Sat 02 Nov 2024 03:54:44 PM EET 
#include <algorithm>
#include <cctype>
#include <string>
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
  string s; 
  getline(cin, s);

  bool flag = false;
  int ans = 0;
  for (int i = 0; i < s.size(); i++) {
    if(isalpha(s[i])){
      if(!flag) ans++;
      flag = true;
    } else flag = false;
  }

  cout << ans << "\n";
}


int main() {
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}
