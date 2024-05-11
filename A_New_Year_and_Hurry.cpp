// ﷽
// problem: A. New Year and Hurry
// URL: https://codeforces.com/problemset/problem/750/A  
// Start: 5/11/2024, 1:05:52 PM
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
    int n, k; cin >> n >> k;
    
    int left = 1, right = n, problmes = 0;; 
    while(left <= right){
        int mid = (left+right)/2;
        if ((mid*(mid+1)/2)*5 + k <= 240){
            problmes = mid;
            left = mid+1;
        } else {
            right = mid-1;
        }
    }

    cout << problmes << "\n";
}

/*
NOTES:
sum = (mim*(mid-1)/2)*5 + k <= 240
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