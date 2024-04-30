// ﷽
// problem: C. Stack
// URL: https://codeforces.com/group/isP4JMZTix/contest/392597/problem/C  
// Start: 4/30/2024, 2:11:24 AM
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
   string s;
    cin >> s;
    int count = 0;
    int total = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if(s[i] == '('){
            count++;
        } else if (s[i] == ')' && count != 0){
            count--;
            total += 2;
        }
    }

    cout << total; 
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