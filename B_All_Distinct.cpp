// ﷽
// problem: B. All Distinct
// URL: https://codeforces.com/problemset/problem/1692/B  
// Start: 5/9/2024, 8:31:43 PM
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
    map<int,int> freq;
    for(int i = 0; i < n; i++) {
        int num; cin >> num;
        freq[num]++;
    }
    if((n-freq.size())%2 == 0) cout << freq.size() << "\n";
    else cout << freq.size()-1 << "\n";
}  

/*
NOTES:
1 
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