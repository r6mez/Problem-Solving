// ﷽
// problem: D - Soltan and Haiku
// URL: https://vjudge.net/contest/630348#problem/D  
// Start: 5/23/2024, 5:41:20 PM
#include <iostream>
#include <algorithm>
using namespace std;



void solve(){
    int five = 0, seven = 0;
    for (int i = 0; i < 3; i++)
    {
        int n; cin >> n;
        if(n==5)five++;
        if(n==7)seven++;
    }
    if(five == 2 && seven == 1) cout << "YES";
    else cout << "NO";
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