// ﷽
// problem: A. Marathon
// URL: https://codeforces.com/problemset/problem/1692/A  
// Start: 5/5/2024, 11:13:56 PM
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
    int a,b,c,d; cin >> a >> b >> c >> d;
    int counter = 0;
    if(b>a) counter++;
    if(c>a) counter++;
    if(d>a) counter++;
    cout << counter << "\n";
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