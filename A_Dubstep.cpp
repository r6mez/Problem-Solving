// ﷽
// problem: A. Dubstep
// URL: https://codeforces.com/problemset/problem/208/A  
// Start: 5/1/2024, 7:56:24 AM
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
    int i;
    while ((i = s.find("WUB")) != string::npos){
        s.erase(s.begin()+i, s.begin()+i+3);
        if(*(s.begin()+i-1) != ' ') s.insert(s.begin()+i, ' ');
    }
    cout << s;
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