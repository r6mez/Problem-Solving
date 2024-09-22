// ﷽
// problem: A. Sum
// URL: https://codeforces.com/problemset/problem/1742/A  
// Start: 4/30/2024, 5:26:15 AM
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
    if(a+b == c || a+c == b || b+c == a) cout << "YES\n";
    else cout << "NO\n";
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