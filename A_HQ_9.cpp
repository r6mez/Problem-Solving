// ﷽
// problem: A. HQ9+
// URL: https://codeforces.com/problemset/problem/133/A  
// Start: 5/1/2024, 7:49:13 AM
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
    for(char c : s) {
        if(c == 'H' || c == 'Q'|| c == '9') {
            cout << "YES";
            return;
        }
    }
    cout << "NO";
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