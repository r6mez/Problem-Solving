// ﷽
// problem: B. Not Quite Latin Square
// URL: https://codeforces.com/contest/1915/problem/B  
// Start: 5/6/2024, 11:46:35 AM
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
    string sq[3];
    for(string &s : sq) cin >> s;
    for (int i = 0; i < 3; i++)
    {
        bool a = false, b = false, c = false;
        for (int j = 0; j < 3; j++)
        {
            if(sq[i][j] == 'A') a = true;
            if(sq[i][j] == 'B') b = true;
            if(sq[i][j] == 'C') c = true;
        }
        if(!a) cout << "A\n";
        if(!b) cout << "B\n";
        if(!c) cout << "C\n";
    }
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