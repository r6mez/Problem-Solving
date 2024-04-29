// ﷽
// problem: A. Two Friends
// URL: https://codeforces.com/contest/1969/problem/0  
// Start: 4/29/2024, 5:34:54 AM
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
    int p[n];
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    bool is2 = false;
    for (int i = 0; i < n; i++)
    {
        if(p[p[i]-1] == i+1) {
            is2 = true;
            break;
        }
    }

    if(is2) cout << 2 << "\n";
    else cout << 3 << "\n";
}

/*
NOTES:

5
3 1 2 5 4
p[i] == p[p[i]]
i3      i4
v5      v  


4
2 3 4 1
3 4 1 2 

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