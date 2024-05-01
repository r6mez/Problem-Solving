// ﷽
// problem: A. Even Odds
// URL: https://codeforces.com/problemset/problem/318/A  
// Start: 5/1/2024, 6:17:17 AM
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
    ll n, k; cin >> n >> k;
    if(k <= (n+1)/2) cout << (1 + 2*(k-1));
    else cout << (2*k - ((n+1)/2)*2);
}
/*
1 3 5 7 | 2 4 6 
1 2 3 4 | 5 6 7 

1 3 5 7 | 2 4 6 8
1 2 3 4 | 5 6 7 8


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