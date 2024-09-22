// ﷽
// problem: B. Prefiquence
// URL: https://codeforces.com/contest/1968/problem/B  
// Start: 5/2/2024, 5:56:15 AM
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
    ll n, m; cin >> n >> m;
    string a, b; cin >> a >> b;
    ll k = 0, j = 0;
    for (ll i = 0; i < n; i++)
    {
        while(j < m && a[i] != b[j] ){
            j++;
        }
        if(a[i] == b[j]) k++;
        if(j >= m) break;
        else j++;
    }
    cout << k << "\n";
}

/*
NOTES:
10011
1110

100
0

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