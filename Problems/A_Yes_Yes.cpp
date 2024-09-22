// ﷽
// problem: A. Yes-Yes?
// URL: https://codeforces.com/problemset/problem/1759/A  
// Start: 5/5/2024, 10:49:38 PM
#include <iostream>
#include <algorithm>
#include <string>
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

string yes = "YesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYes";

void solve(){
    string s; cin >> s;
    int size = s.size();
    bool isFound = false;
    
    for (int i = 0; i <= yes.size()-size; i++)
    {
        if(yes.substr(i, size) == s){
            isFound = true;
            break;
        } 
    }

    if(isFound) cout << "YES\n";
    else cout << "NO\n";
}

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