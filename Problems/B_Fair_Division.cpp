// ﷽
// problem: B. Fair Division
// URL: https://codeforces.com/problemset/problem/1472/B  
// Start: 5/6/2024, 7:02:28 PM
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
    int ones = 0, twos = 0;
    while(n--) {
        int x; cin >> x;
        if(x == 1) ones++;
        else twos++;
    }

    if((ones%2 == 0) && !(ones == 0 && twos%2 != 0)) cout << "YES\n";
    else cout << "NO\n";
}

/*
2 -> odd -> i need even one's
2 -> even -> no one's or even one's 
2 -> 0  -> 
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