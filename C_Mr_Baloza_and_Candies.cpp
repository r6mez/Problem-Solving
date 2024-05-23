// ﷽
// problem: C - Mr. Baloza and Candies
// URL: https://vjudge.net/contest/630348#problem/C  
// Start: 5/23/2024, 5:39:17 PM
#include <iostream>
#include <algorithm>
using namespace std;


void solve(){
    int n; cin >> n;
    int sum = (n*(n+1))/2;
    cout << sum;
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