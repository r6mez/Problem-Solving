// ﷽
// problem: C. Clock and Strings
// URL: https://codeforces.com/contest/1971/problem/C  
// Start: 5/10/2024, 4:42:44 PM
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
    int a, b, c, d; 
    cin >> a >> b >> c >>d;
    if((max(a,b) > max(c,d) && min(a,b) < min(c,d))
        || (max(a,b) < max(c,d) && min(a,b) > min(c,d))
        || (a < min(c,d) && b < min(c,d))
        || (c < min(a,b) && d < min(a,b))) cout << "NO\n";
    else cout << "YES\n";
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