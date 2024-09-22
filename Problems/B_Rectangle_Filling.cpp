// ﷽
// problem: B. Rectangle Filling
// URL: https://codeforces.com/contest/1966/problem/B  
// Start: 4/27/2024, 6:27:22 AM
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

void solve() {
    ll n, m;
    cin >> n >> m;
    vll b(4,0);
    vll w(4,0);
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c = v[i][j];
 
            if (c == 'B') {
                if (i == 0)
                    b[0] = 1;
                if (j == 0)
                    b[1] = 1;
                if (i == n-1)
                    b[2] = 1;
                if (j == m-1)
                    b[3] = 1;
            } else {
                if (i == 0)
                    w[0] = 1;
                if (j == 0)
                    w[1] = 1;
                if (i == n-1)
                    w[2] = 1;
                if (j == m-1)
                    w[3] = 1;
            }
 
        }
    }
 
    bool canBeWhite = true, canBeBlack = true;
    for (int i = 0; i < 4; i++)
    {
        if(w[i] == 0) canBeWhite = false;
        if(b[i] == 0) canBeBlack = false;
    }

    if(canBeBlack || canBeWhite) cout << "YES\n";
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