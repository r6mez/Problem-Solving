// ﷽
// problem: B. Different String
// URL: https://codeforces.com/contest/1971/problem/B  
// Start: 5/10/2024, 4:37:57 PM
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, 
                    tree_order_statistics_node_update>;
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vll vector<long long>

void solve(){
  string s; cin >> s;
  bool isPos = false;
  for (int i = 1; i < s.size(); i++)
  {
    if(s[0] != s[i]) {
        swap(s[0], s[i]);
        isPos = true;
        break;
    }
  }
  if(isPos) {
    cout << "YES\n" << s << "\n";
  } else {
    cout << "NO\n";
  }
}

/*
NOTES:

*/

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    int t = 1; 
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}