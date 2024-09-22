// ﷽
// problem: D. List & Set
// URL: https://codeforces.com/group/isP4JMZTix/contest/392597/problem/D  
// Start: 4/29/2024, 11:44:51 PM
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
    ll n; cin >> n;
    set<ll> s;
    for (int i = 0; i < n; i++)
    {
        ll num; cin >> num;
        s.insert(num);
    }
    cout << s.size();
}

/*
NOTES:
    
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