// ﷽
// problem: B. 01 Game
// URL: https://codeforces.com/problemset/problem/1373/B  
// Start: 5/5/2024, 7:55:10 PM
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
    int zeros = 0, ones = 0; 
    for(char c : s) {
        if(c == '0') zeros++;
        else ones++;
    }

    if(min(zeros,ones)%2 == 0) cout << "NET\n";
    else cout << "DA\n";
}

/*
NOTES:
1011001
0001111

3 zeros 
4 ones

3 moves


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