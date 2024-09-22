// ﷽
// problem: A. I Wanna Be the Guy
// URL: https://codeforces.com/problemset/problem/469/A  
// Start: 4/29/2024, 5:27:53 AM
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
    map<int,int> passedLevels;
    int x; cin >> x;
    while(x--) {
        int level; cin >> level;
        passedLevels[level]++;
    }
    
    int y; cin >> y;
    while(y--) {
        int level; cin >> level;
        passedLevels[level]++;
    }

    if(passedLevels.size() == n) cout << "I become the guy.";
    else cout << "Oh, my keyboard!";
}

/*
NOTES:

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