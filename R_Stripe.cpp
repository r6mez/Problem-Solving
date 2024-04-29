// ﷽
// problem: R. Stripe
// URL: https://codeforces.com/group/isP4JMZTix/contest/386415/problem/R  
// Start: 4/29/2024, 1:33:02 AM
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
using namespace std;
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vll vector<long long>

void solve(){
   int n; cin >> n;
   int sum[n+1] = {0};
   for (int i = 1; i <= n; i++)
   {
        int num; cin >> num;
        sum[i] = sum[i-1] + num;
   }

   int counter = 0;
   for (int i = 1; i < n; i++)
   {
        if((sum[i]) == (sum[n] - sum[i])) counter++;
   }
   
   cout << counter;
}

/*
NOTES:
    1 5 -6 7 9 -16 0 -2 2
  0 1 6 0  7 16 0  0 -2 0 
*/

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    int t = 1; 
    // cin >> t;
    while (t--){
        solve();
    }
    return 0;
}