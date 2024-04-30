// ﷽
// problem: B. Coin Games
// URL: https://codeforces.com/contest/1972/problem/B  
// Start: 4/30/2024, 5:52:29 AM
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
    int n;cin >> n;
    string coins; cin >> coins;
    int upCoins = 0; 
    for (char coin : coins) {
        if (coin == 'U') {
            ++upCoins;
        }
    }
    
    if(upCoins != 0 && upCoins % 2 != 0) cout << "YES\n";
    else cout << "NO\n";
}

/*
NOTES:
n coins up or down
alice first 
facing up -> remove -> filps the to adjecent coins
if(n == 2) one removed and no flip
if(no up coins) the player losses



UDDUD 
UDDUD Alice 1
UDUU Bob 4
DDD alice loses


DUD choose U
UDU choose D
UDD Choose 2



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