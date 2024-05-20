// ﷽
// problem: A. Phone Desktop
// URL: https://codeforces.com/contest/1974/problem/0  
// Start: 5/20/2024, 5:35:33 PM
#include <bits\stdc++.h>
#include <algorithm>
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
#define all(v)  v.begin(), v.end()
 
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
    int ones, twos; cin >> ones >> twos;
    int screensWithTwoTwos = twos/2;
    int screensWithOneTwo = twos%2;
    int emptyCellsForOnes = 7*screensWithTwoTwos + 11*screensWithOneTwo;
    int remainingOnes = ones-emptyCellsForOnes;
    int screens = screensWithTwoTwos + screensWithOneTwo;
    if(remainingOnes > 0) screens += ceil(remainingOnes/15.0);
    cout << screens << "\n";
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