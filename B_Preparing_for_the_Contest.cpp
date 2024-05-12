// ﷽
// problem: B. Preparing for the Contest
// URL: https://codeforces.com/problemset/problem/1914/B  
// Start: 5/12/2024, 9:57:15 PM
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
    int n, r; cin >> n >> r;
    int left = n-1;
    
    for (int i = 1; i < n-r; i++)
    {
        cout << n-i+1 << " ";
    }

    for (int i = 1; i <= r+1; i++)
    {
        cout << i << " ";
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
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}