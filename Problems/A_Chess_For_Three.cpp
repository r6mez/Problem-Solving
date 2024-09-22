// ﷽
// problem: A. Chess For Three
// URL: https://codeforces.com/contest/1973/problem/0  
// Start: 5/17/2024, 5:35:16 PM
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
    int p1, p2, p3; cin >> p1 >> p2 >> p3;
    int sum = p1 + p2 + p3;
    if(sum%2 != 0) {
        cout << -1 << "\n";
    } else {
        int games = sum/2;
        cout << (p3 > (p1+p2)? (p1+p2) : games) << "\n";
    }
}

/*
NOTES:
0 0 0  0
0 1 1  1 
1 1 2  2
3 4 5  6 
1 1 10 2

3 4 5 
0 1 1 1
1 1 2 2
1 2 3 3
2 2 4 4 
2 3 5 5 
3 4 5 6 

0 1 1


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