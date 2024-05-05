// ﷽
// problem: B. Circle Game
// URL: https://codeforces.com/problemset/problem/1695/B  
// Start: 5/5/2024, 8:48:36 PM
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
    vi piles(n); 
    int minPile = INT_MAX, minPileIndex = 0;
    for (int i = 0; i < n; i++) {
        cin >> piles[i];
        if(minPile > piles[i]){
            minPile = piles[i];
            minPileIndex = i;
        }
    }

    if(n%2 != 0) {
        cout << "Mike\n";
    } else {
        if(minPileIndex%2 != 0){
            cout << "Mike\n";
        } else {
            cout << "Joe\n";
        }
    }
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