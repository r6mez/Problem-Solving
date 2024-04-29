// ﷽
// problem: N. Ilya and Queries
// URL: https://codeforces.com/group/isP4JMZTix/contest/386415/problem/N  
// Start: 4/29/2024, 12:14:35 AM
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
    int m; cin >> m;

    s += ' ';
    int pairSum[s.size()] = {0};
    for (int i = 1; i < s.size(); i++)
    {
        pairSum[i] = pairSum[i-1] + (s[i-1] == s[i]);
    }

    while(m--){
        int l, r; cin >> l >> r;
        int sum = (pairSum[r-1] - pairSum[l-1]);
        cout << sum << "\n";
    }
    
} 

/*
NOTES:
......
 111111
0123456

      #..###
pair 0011233
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