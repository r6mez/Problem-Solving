// ﷽
// problem: D. Unnatural Language Processing
// URL: https://codeforces.com/contest/1915/problem/D  
// Start: 5/6/2024, 12:38:13 PM
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

bool isV(char c){
    if(c == 'a' || c == 'e') return true;
    else return false;
}

bool isC(char c){
    if(c == 'b' || c == 'c' || c == 'd') return true;
    else return false;
}

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    string result = "";

    for (int i = 0; i < n;) {
        if(i+3 < n && isC(s[i+3])){
            result += s.substr(i, 3);
            result += ".";
            i += 3;
        } else if (i+3 < n && !isC(s[i+3])) {
            result += s.substr(i, 2);
            result += ".";
            i += 2;
        } else {
            result += s.substr(i, n);
            break;
        }
    }

    cout << result << "\n";
}

/*
NOTES:
bacedbab
ba ced bab

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