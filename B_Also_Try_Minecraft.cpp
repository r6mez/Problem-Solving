// ﷽
// problem: B. Also Try Minecraft
// URL: https://codeforces.com/problemset/problem/1709/B  
// Start: 5/1/2024, 8:41:25 AM
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
    int n, m; cin >> n >> m;
    ll a[n]; for(ll &i : a) cin >> i;
    ll sumOfDamage[n+1] = {0};
    ll sumOfDamageReversed[n+1] = {0};
    for (int i = 1; i <= n; i++){ 
        ll addedValue = (a[i-1]>a[i] ? a[i-1]-a[i] : 0);
        sumOfDamage[i] = sumOfDamage[i-1] + addedValue;

        ll addedValueReversed = (a[n-i] > a[n-i-1]? a[n-i-1]-a[n-i] : 0);
        sumOfDamageReversed[n-i-1] = sumOfDamageReversed[n-i] + addedValueReversed;
    }
    
    while (m--) {
        int s, t; cin >> s >> t;
        if (s < t) cout << (sumOfDamage[t-1] - sumOfDamage[s-1]) << "\n";
        else cout << (sumOfDamageReversed[s-1] - sumOfDamageReversed[t-1]) << "\n";
    }
}

/*
NOTES:
  10 8 9 6 8 12 7
0 2  2 5 5 5 10 10
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