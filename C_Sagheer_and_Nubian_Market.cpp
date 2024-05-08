// ﷽
// problem: C. Sagheer and Nubian Market
// URL: https://codeforces.com/problemset/problem/812/C  
// Start: 5/8/2024, 10:40:26 PM
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

ll getTotalCost(int k, ll S, vi &baseCosts) {
    vll totalCosts;
    for (int i = 0; i < baseCosts.size(); ++i) {
        totalCosts.push_back(baseCosts[i] + (ll)(i + 1) * k);
    }

    sort(totalCosts.begin(), totalCosts.end());
    ll sum = 0;

    for (int i = 0; i < k; ++i) {
        sum += totalCosts[i];
    }

    return sum;
}


void solve(){
    int n, s; cin >> n >> s;
    vi baseCosts(n); for(int &i : baseCosts) cin >> i;
    

    int left = 0, right = n, maxK = 0;
    ll minTotalCost = LLONG_MAX;
    while(left <= right){
        int mid = left + (right - left) / 2;
        ll totalCost = getTotalCost(mid, s, baseCosts);
        if(totalCost <= s){
            left = mid+1;

        } else {
            right = mid-1;
        }
        maxK = right;
        minTotalCost = min(minTotalCost, totalCost);
    }

    minTotalCost = getTotalCost(maxK, s, baseCosts);

    cout << maxK << " " << minTotalCost;
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