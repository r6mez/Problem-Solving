// ﷽
// problem: B. XOR = Average
// URL: https://codeforces.com/problemset/problem/1758/B  
// Start: 5/1/2024, 8:13:42 AM
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
    if(n%2 != 0){
        while(n--) cout << 1 << " ";
    } else {
        cout << "1 3 ";
        n -= 2;
        while(n-- > 0) cout << 2 << " ";
    }
    cout << "\n";
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