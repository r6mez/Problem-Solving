// ﷽
// problem: J. Unique Elements
// URL: https://codeforces.com/group/isP4JMZTix/contest/392597/problem/J  
// Start: 5/1/2024, 2:03:37 AM
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
    map<ll,ll> freq;
    while(n--) {
        ll x; cin >> x; freq[x]++;
    }

    ll unique = 0;
    for(auto i : freq){
        if(i.second == 1) unique++; 
    }

    cout << unique << "\n";
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