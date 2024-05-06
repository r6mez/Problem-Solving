// ﷽
// problem: C. Two Teams Composing
// URL: https://codeforces.com/contest/1335/problem/C  
// Start: 5/6/2024, 5:32:02 PM
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
    int n;
    cin >> n;
    vector<int> cnt(n + 1);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    int mx = *max_element(cnt.begin(), cnt.end());
    int diff = n - count(cnt.begin(), cnt.end(), 0) + 1;
    cout << max(min(mx - 1, diff), min(mx, diff - 1)) << endl;
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