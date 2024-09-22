// ﷽
// problem: A. Fair Playoff
// URL: https://codeforces.com/problemset/problem/1535/A  
// Start: 5/5/2024, 11:15:45 PM
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
    int s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    
    vi a = {s1,s2,s3,s4};
    sort(a.begin(), a.end());
    int maxNum = a[3], secondMaxNum = a[2];
    
    if(maxNum == max(s1,s2) && secondMaxNum == min(s1,s2)
     ||maxNum == max(s3,s4) && secondMaxNum == min(s3,s4)){
        cout << "NO\n";
    } else {
        cout << "YES\n";
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