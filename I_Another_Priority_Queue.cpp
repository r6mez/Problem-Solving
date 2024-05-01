// ﷽
// problem: I. Another Priority_Queue
// URL: https://codeforces.com/group/isP4JMZTix/contest/392597/problem/I  
// Start: 5/1/2024, 1:38:09 AM
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
    priority_queue<ll> a,b;
    for (ll i = 0; i < n; i++){
        ll x; cin >> x; a.push(x);
    }
    for (ll i = 0; i < n; i++){
        ll x; cin >> x; b.push(x);
    }
    
    int operations = 0;
    while(!a.empty()){
        ll ai = a.top(), bi = b.top();

        if(ai == bi){
            a.pop();
            b.pop();
        } else {
            operations++;
            ll length = to_string(max(ai,bi)).length();
            if(ai > bi){
                a.push(length); a.pop();
            } else {
                b.push(length); b.pop();
            }
        }
    }

    cout << operations << "\n";
}

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