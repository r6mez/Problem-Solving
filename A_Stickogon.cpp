// ﷽
// problem: A. Stickogon
// URL: https://codeforces.com/problemset/problem/1957/A  
// Start: 5/12/2024, 9:47:48 PM
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
    int n; cin >> n;
    map<int, int> m;
    while(n--) {
        int i;
        cin >> i;
        m[i]++;
    }
    int counter = 0;
    for(auto i : m) counter += (i.second)/3; 
    cout << counter << "\n";
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