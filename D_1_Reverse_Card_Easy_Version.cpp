// ﷽
// problem: D1. Reverse Card (Easy Version)
// URL: https://codeforces.com/contest/1972/problem/D1  
// Start: 4/30/2024, 6:30:44 AM
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

ll GCD(ll a, ll b){
    return (b!=0? GCD(b,a%b) : a);
}

void solve(){
    ll n,m; cin >> n >> m;

    ll pairs = 0;
    for (ll b = 1; b <= m; b++)
    {
        for (ll a = b; a <= n; a += b)
        {
            if (((a+b)%(b*GCD(a,b))) == 0)
                pairs++;
        }
    }
    cout << pairs << "\n";
}

int main() {
    // ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    int t = 1; 
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}