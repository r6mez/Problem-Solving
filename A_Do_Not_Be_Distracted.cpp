// ﷽
// problem: A. Do Not Be Distracted!
// URL: https://codeforces.com/problemset/problem/1520/A  
// Start: 5/11/2024, 7:58:40 PM
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
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, 
                    tree_order_statistics_node_update>;
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vll vector<long long>

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    map<char, int> m;
    char lastChar = s[0];
    bool gotDistracted = false;
    for(char c : s){
        if(lastChar != c && m[c] != 0) {
            gotDistracted = true;
            break;
        }
        m[c]++;
        lastChar = c;
    }
    if(!gotDistracted) cout << "YES\n";
    else cout << "NO\n";
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