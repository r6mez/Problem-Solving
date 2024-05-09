// ﷽
// problem: A. Black Square
// URL: https://codeforces.com/problemset/problem/431/A  
// Start: 5/9/2024, 8:56:31 PM
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
   int a1, a2, a3, a4; cin >> a1 >> a2 >> a3 >> a4;
   string s; cin >> s;
   int sum = 0;
   for(char c: s) {
        if(c == '1') sum += a1;
        else if (c == '2') sum += a2;
        else if (c == '3') sum += a3;
        else if (c == '4') sum += a4;
   } 
   cout << sum;
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