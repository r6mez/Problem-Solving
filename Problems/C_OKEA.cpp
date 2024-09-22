// ﷽
// problem: C. OKEA
// URL: https://codeforces.com/problemset/problem/1634/C  
// Start: 5/14/2024, 12:05:19 AM
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
    if(k == 1) {
        cout << "YES\n";
        while(n) cout << n-- << "\n";
        return;
    }

    if (n%2 != 0) {
        cout << "NO\n";
    }
    else {
        int odd = 1;
        int even = 2;
        cout << "YES\n";
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < k; j++)
            {
                if(i%2 != 0) {
                    cout << odd << " ";
                    odd += 2;
                } else {
                    cout << even << " "; 
                    even += 2;
                }
            }
            cout << "\n";
        }
    }
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