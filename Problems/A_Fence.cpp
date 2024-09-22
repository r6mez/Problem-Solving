// ﷽
// problem: A. Fence
// URL: https://codeforces.com/group/isP4JMZTix/contest/386415/problem/A  
// Start: 4/26/2024, 12:56:00 AM
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vll vector<long long>
 
void solve(){
    ll n, k; cin >> n >> k;
    ll a[n], sum[n+1] = {0};
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
 
    for (ll i = 0; i < n; i++)
    {
        sum[i+1] = sum[i] + a[i];
    }
    
    ll minSum = INT_MAX;
    ll minIndex = 0;
    for (ll i = 1; i+k-1 <= n; i++)
    {
        ll sumValue = (sum[i+k-1] - sum[i-1]);
        if(minSum >= sumValue){
            minSum = sumValue;
            minIndex = i;
        }
    }
 
    cout << minIndex;
}
 
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

/*

7 3
1 2 6 1 1 7 1

1 2 6 1 = 10
2 6 1 1 = 10
6 1 1 7 = 15
1 1 7 1 = 10 

*/