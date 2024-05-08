// ﷽
// problem: N. Sum of Cubes
// URL: https://codeforces.com/group/isP4JMZTix/contest/379072/problem/N  
// Start: 5/8/2024, 8:36:31 PM
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

bool theresAandB(){
    ll x; cin >> x;
    if(x == 1) return false;
    for (ll a = 1; a < cbrt(x); a++)
    {
        ll left = 1, right = cbrt(x);
        while(left <= right){
            ll mid = left + (right - left) / 2;
            ll currentValue = a * a * a + mid * mid * mid;
            if(currentValue == x) {
                return true;
            }
            else if(currentValue < x){
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return false;
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
        cout << (theresAandB()? "YES\n" : "NO\n");
    }
    return 0;
}