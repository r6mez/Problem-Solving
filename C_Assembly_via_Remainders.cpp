// ﷽
// problem: C. Assembly via Remainders
// URL: https://codeforces.com/contest/1968/problem/C  
// Start: 5/2/2024, 6:12:46 AM
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

void solve() {
    ll n; cin >> n;
    ll a[n-1], x[n];
    ll maxNum = -1;
    for (ll& i : a) {
        cin >> i;
        maxNum = max(maxNum,i);
    }

    x[0] = maxNum+1;
    cout << x[0] << " ";

    for (ll i = 0; i < n-1; i++)
    {
        x[i+1] = (x[i] + a[i]);
        cout << x[i+1] << " ";
    }
    
    cout << "\n";
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}