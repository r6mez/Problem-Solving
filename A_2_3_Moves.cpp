// ﷽
// problem: A. 2-3 Moves
// URL: https://codeforces.com/problemset/problem/1716/A  
// Start: 5/3/2024, 8:55:08 AM
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
    if(n==4 || n==1) {cout << 2 << "\n"; return;}
    

    ll steps = 0;
    if(n%3 == 0) steps = n/3;
    else steps = n/3 + 1;

    cout << steps << "\n";
}

/*
NOTES:
1 +3 -2
2

3 +3
1 

4 +2 +2
2

12 +3 +3 +3 +3 
4 

8 +3 +3 +2

n%3==0 
min = n/3

min = n/3 + 1

1198

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