// ﷽
// problem: G. K-th Not Divisible by n
// URL: https://codeforces.com/group/isP4JMZTix/contest/379072/problem/G  
// Start: 5/8/2024, 3:14:41 PM
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

/*
3 7
1 2 4 5 7 8 10 
divisiable = 3 6 
7/2 = 3

4 12
1 2 3 5 6 7 9 10 11 13 14 15 
divisiable = 4 8 12 
12/4 = 3
*/

bool isValid(long long n, long long k, long long mid) {
    // Count of numbers not divisible by n from 1 to mid
    long long count = mid - (mid / n);
    return count >= k;
}

ll searchForKthNumberDivisiableByN(ll n, ll k){
    long long left = 1, right = 2*k;
    long long ans = 0;
    while (left <= right) {
        long long mid = (right + left) / 2;
        if (isValid(n, k, mid)) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
        ans = left;
    }
    return ans;
}

void solve(){
    ll n, k; cin >> n >> k;
    ll answer = searchForKthNumberDivisiableByN(n,k);
    // ll answer = lower_bound((ll)1, 2*k, k, isValid);
    cout << answer << "\n";
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