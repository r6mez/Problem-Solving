// ﷽
// problem: A. Odd One Out
// URL: https://codeforces.com/contest/1915/problem/A  
// Start: 5/6/2024, 11:44:19 AM
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
    int a, b, c; cin >> a >> b >> c;
    if(a == b) cout << c << "\n";
    else if(b == c) cout << a << "\n";
    else if(a == c) cout << b << "\n";
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