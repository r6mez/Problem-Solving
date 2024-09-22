// ﷽
// problem: F. Sereja and Suffixes
// URL: https://codeforces.com/group/isP4JMZTix/contest/386415/problem/F  
// Start: 4/29/2024, 12:55:17 AM
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
    int n,m; cin >> n >> m;

    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    

    map<int,int> frequency;
    int prefixSum[n+1] = {0};
    for (int i = n-1; i >= 0; i--)
    {
        prefixSum[i] = prefixSum[i+1] + (frequency[a[i]] == 0);
        frequency[a[i]]++;
    }
    
    for (int i = 0; i < m; i++)
    {
        int l; cin >> l;
        cout << (prefixSum[l-1]) << "\n";
    }
}

/*
NOTES:
  1 2 3 4 1 2 3 4 5 6
0 1 2 3 4 4 4 4 4 5 6
  6 6 6 6 6 5 4 3 2 1 0
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