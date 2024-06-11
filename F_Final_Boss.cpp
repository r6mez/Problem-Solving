// ﷽
// problem: F. Final Boss
// URL: https://codeforces.com/contest/1985/problem/F  
// Start: 6/11/2024, 6:52:13 PM
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <bitset>
using namespace std;
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vll vector<long long>
#define all(v)  v.begin(), v.end()

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for(const auto& i : v) os << i << ' ';
    return os;
}
 
template<typename T>
istream& operator>>(istream& is, vector<T>& v) {
    for(auto& i : v) is >> i;
    return is;
}

void solve(){
    int h, n; cin >> h >> n;
    vi dam(n); cin >> dam;
    vi cldw(n); cin >> cldw;

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> currCoolDowns;
    for (int i = 0; i < n; i++) {
        currCoolDowns.push({0, i});
    }
    
    ll turns = 0;
    
    while (h > 0) {
        ll currTurn = currCoolDowns.top().first;
        vector<pair<ll, ll>> newCoolDowns;
        
        while (!currCoolDowns.empty() && currCoolDowns.top().first == currTurn) {
            ll attackIndex = currCoolDowns.top().second;
            h -= dam[attackIndex];
            newCoolDowns.push_back(make_pair(currTurn + cldw[attackIndex], attackIndex));
            currCoolDowns.pop();
        }
        
        for (auto pir : newCoolDowns) {
            currCoolDowns.push(pir);
        }
        
        turns = currTurn + 1;
    }
    cout << turns << "\n";
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