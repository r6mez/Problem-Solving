// ﷽
// problem: A. 2023
// URL: https://codeforces.com/problemset/problem/1916/A  
// Start: 5/15/2024, 11:20:59 PM
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
      ll n, k; cin >> n >> k;
        ll pr = 1;
        for (int i = 0; i < n; i++){
            int x; cin >> x;
            pr *= x;
        }
        if((pr <= 2023) and (2023 % pr) == 0){
            cout << "YES\n";
            cout << (2023/pr) << " ";
            for (int i = 0; i < k-1; i++) cout << "1 ";
            cout << '\n';
        }
        else cout << "NO\n";
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
        solve();
    }
    return 0;
}