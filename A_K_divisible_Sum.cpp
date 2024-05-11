// ﷽
// problem: A. K-divisible Sum
// URL: https://codeforces.com/problemset/problem/1476/A  
// Start: 5/11/2024, 1:41:44 PM
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

bool canFormArray(int n, int k, int maxElement) {
    int sum = ((n / k) * maxElement * k) + (min(n % k, maxElement) * (n / k + 1));
    // Check if the sum is divisible by k
    return sum % k == 0;
}

void solve(){
    double n, k; cin >> n >> k;
    double x = ceil(n/k);
    double s = x*k;
    int ans = ceil(s/n);
    cout << ans << "\n";
}

/*
NOTES:
s%k == 0; -> s = x*k = 1*k = 2*k = ..
x = ceil(n/k);
s = x*k
ans = ceil(s/n)

1 5
5 

4 3
1 1 2 2 

8 8
1 1 1 1 1 1 1 1

8 17
1 2 2 2 2 2 3 3
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

