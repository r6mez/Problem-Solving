// ﷽
// problem: E. Cells Arrangement
// URL: https://codeforces.com/contest/1968/problem/E  
// Start: 5/2/2024, 8:12:44 AM
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
    cout << "1 2\n";
    for (int i = 1; i <= n; i++)
        if(i!=2) cout << i << " " << i << "\n";
    cout << "\n";
}

/*
NOTES:
n pairs
1 1 
2 2
3 3 
4 4 should give you 0 2 4 6.. even 

1 1 and any pair gives 0 2 4 6 
1 2 and any pair gives 1 3 5 7 ..
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