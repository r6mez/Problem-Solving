// ﷽
// problem: B. Map
// URL: https://codeforces.com/group/isP4JMZTix/contest/392597/problem/B  
// Start: 4/29/2024, 10:41:04 AM
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
    map<string, int> m; 
    while(n--){
        string s; cin >> s;
        if(m[s] == 0) cout << "OK\n";
        else cout << (s + to_string(m[s])) << "\n";
        m[s]++;
    }
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