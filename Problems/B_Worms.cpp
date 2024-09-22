// problem: B. Worms
// URL: https://codeforces.com/problemset/problem/474/B  
// Start: 6/6/2024, 3:33:40 PM
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
    int n;
    cin >> n;
    vector <ll> piles(n+1);
    for(int i = 1 ; i <= n ; i++){
        cin >> piles[i];
        piles[i] += piles[i-1];
    }
 
    int t; cin >> t;
    while(t--){
        int x;
        cin >> x;
        int idx = lower_bound(all(piles), x) - piles.begin();
        cout << idx << '\n';
    }
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
