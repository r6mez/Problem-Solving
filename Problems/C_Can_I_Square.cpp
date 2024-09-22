// ﷽
// problem: C. Can I Square?
// URL: https://codeforces.com/contest/1915/problem/C  
// Start: 5/6/2024, 11:51:00 AM
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
    ll sum = 0;
    while(n--) {
        ll x; cin >> x; sum += x;
    }    
    ll sq = sqrt(sum);
    if(sq == sqrt(sum)) cout << "YES\n";
    else cout << "NO\n";
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