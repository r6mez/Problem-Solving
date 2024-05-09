// ﷽
// problem: B. Even Array
// URL: https://codeforces.com/problemset/problem/1367/B  
// Start: 5/9/2024, 9:04:35 PM
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
    int counterEven = 0, counterOdd = 0;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        if (x % 2 != i % 2) {
            if (x % 2 == 0) {
                counterEven++;
            }
            else {
                counterOdd++;
            }
        }
    }

    cout << (counterEven == counterOdd ? counterEven : -1) << "\n";
}

/*
NOTES:
4 9 2 1 18 3 0
0 1 0 1 0 1 0

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