// ﷽
// problem: A. Lucky?
// URL: https://codeforces.com/problemset/problem/1676/A  
// Start: 4/30/2024, 5:24:14 AM
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
    string s; cin >> s;
    int first3 = 0, second3 = 0;
    for (int i = 0; i < 6; i++)
    {
        if(i<3) first3 += s[i];
        else second3 += s[i];
    }
    
    if(first3 == second3) cout << "YES\n";
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