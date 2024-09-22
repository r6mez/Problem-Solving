// ﷽
// problem: E. Interesting drink
// URL: https://codeforces.com/group/isP4JMZTix/contest/379072/problem/E  
// Start: 5/8/2024, 4:58:48 PM
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
3 10 8 6 11
        3 6 8 10 11 
isV 4:  1 0 0 0  0  
isV 10: 1 1 1 1  0  
isV 11: 1 1 1 1  1  
*/

bool isValid(int coins, int price){
    return (coins >= price);
}

int searchShopsCanBuyFrom(int coins, vi &prices){
    int left = 0, right = prices.size()-1;
    int answer = 0;
    while(left <= right){
        int mid = (right+left)/2;
        if(isValid(coins, prices[mid])){
            left = mid+1;
        } else {
            right = mid-1;
        }
        answer = left;
    }
    return answer;
}

void solve(){
    int n; cin >> n;
    vi prices(n); 
    for (int i = 0; i < n; i++) cin >> prices[i];
    sort(prices.begin(), prices.end());

    int q; cin >> q;
    while(q--){
        int coins; cin >> coins;
        // cout << searchShopsCanBuyFrom(coins, prices) << "\n";

        // Find the upper bound of coins in the sorted prices
        auto it = upper_bound(prices.begin(), prices.end(), coins);
        // The number of shops he can buy from is the index of the upper bound
        cout << distance(prices.begin(), it) << "\n";
    }
}

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