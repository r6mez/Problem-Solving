// ﷽
// problem: K. Alice, Bob and Chocolate
// URL: https://codeforces.com/group/isP4JMZTix/contest/380008/problem/K  
// Start: 5/19/2024, 5:00:44 PM
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
 
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for(const auto& i : v) os << i << ' ';
    return os;
}
 
template<typename T>
istream& operator>>(istream& is, vector<T>& v) {
    for(auto& i : v) is >> i;
    return is;
}

void solve(){
    int n; cin >> n;
    vi bars(n); cin >> bars;
    int alice = 0, bob = 0;
    int l = 0, r = n-1;
    
    while (l <= r){
        if(alice <= bob){
            alice += bars[l++];
        } else {
            bob += bars[r--];
        }
    }

    cout << l << " " << (n-1 - r);
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