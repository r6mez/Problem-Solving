// ﷽
// problem: B. Points on Plane
// URL: https://codeforces.com/problemset/problem/1809/B  
// Start: 5/11/2024, 3:48:08 PM
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
    ll n; cin >> n;
    ll cost = 0;
    for (ll i = 0; i < n; i++)
    {
        int left = i, right = n;

    }
    
}

/*
NOTES:
    you place n ships
    cost of ship is |x| + |y|
    cost of placing n ships is max |x| + |y| of the ships 
    we need the min cost to place n ships 
    distance between each pair of chips must be strictly greater than 1 (there's 1 x, y difference between each point)

    for each x, search y 
    x = -1 | y = 0, 
    x = 0  | y = -1, 1
    x = 1  | y = 0, 

   (-1,  0)
   ( 0, -1)
   ( 0,  1)
   ( 1,  0)


                    |
                    |
                  * *
--------------------|-*--------------
                    *
                    |
                    | 
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