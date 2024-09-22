// ﷽
// problem: A. cAPS lOCK
// URL: https://codeforces.com/problemset/problem/131/A  
// Start: 5/14/2024, 8:24:44 PM
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
    string s; cin >> s;
    bool firstIsLower = true, othersAreUpper = true, allUpper = true;
    if(isupper(s[0])) firstIsLower = false;
    else allUpper = false;
    for(int i = 1; i < s.size(); i++) if(islower(s[i])) {othersAreUpper = false; allUpper = false;}

    if((firstIsLower && othersAreUpper) || allUpper) {
        if(firstIsLower) s[0] = toupper(s[0]);
        else s[0] = tolower(s[0]);
         for (int i = 1; i < s.size(); i++)
            s[i] = tolower(s[i]);
    }
    cout << s << "\n";
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