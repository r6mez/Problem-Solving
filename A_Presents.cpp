// ﷽
// problem: A. Presents
// URL: https://codeforces.com/problemset/problem/136/A  
// Start: 5/7/2024, 4:30:53 PM
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
    int a[1000], b[1000];
    int n;
	cin>>n;
	for (int i=0; i<n; ++i)
		cin>>a[i], b[a[i]]=i+1;
	for (int i=1; i<=n; ++i)
		cout<<b[i]<<' ';
}

/*
NOTES:

*/

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    int t = 1; 
    // cin >> t;
    while (t--){
        solve();
    }
    return 0;
}