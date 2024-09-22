// ﷽
// problem: B. Borze
// URL: https://codeforces.com/problemset/problem/32/B  
// Start: 5/6/2024, 6:33:03 PM
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
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i] == '.') {
            cout << "0";
        }
        else if (s[i] == '-' && s[i+1] == '.'){ 
            cout << "1";
            i++;
        } 
        else if (s[i] == '-' && s[i+1] == '-'){
            cout << "2";
            i++;
        }
    }
    cout << "\n";
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