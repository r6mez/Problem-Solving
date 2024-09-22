// ﷽
// problem: A. Is your horseshoe on the other hoof?
// URL: https://codeforces.com/problemset/problem/228/A  
// Start: 4/29/2024, 5:16:41 AM
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
    map<int,int> colors;
    for (int i = 0; i < 4; i++)
    {
        int color; cin >> color;
        colors[color]++;
    }
    cout << (4-colors.size());
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