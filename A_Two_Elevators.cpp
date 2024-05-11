// ﷽
// problem: A. Two Elevators
// URL: https://codeforces.com/problemset/problem/1729/A  
// Start: 5/11/2024, 8:06:44 PM
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
    int a, b, c; cin >> a >> b >> c;
    int elev1 = a-1;
    int elev2 = b<c? (c-b)+(c-1) : b-1;
    if(elev1 == elev2) cout << 3 << "\n";
    else if(elev1 < elev2) cout << 1 << "\n";
    else cout << 2 << "\n";
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