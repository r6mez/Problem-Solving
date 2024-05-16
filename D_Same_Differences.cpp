// ﷽
// problem: D. Same Differences
// URL: https://codeforces.com/problemset/problem/1520/D  
// Start: 5/16/2024, 9:31:33 PM
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

void solve() {
    int n; cin >> n;
    map<int, int> a;
    long long res = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x -= i;
        res += a[x];
        a[x]++;
    }
    cout << res << endl;
}

/*
NOTES:
3 5 1 4 6 6


  1 2 3 4 5
    1 2 3 4
      1 2 3
        1 2
          1

*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}