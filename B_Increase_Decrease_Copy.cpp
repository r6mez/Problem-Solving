// ﷽
// problem: B. Increase/Decrease/Copy
// URL: https://codeforces.com/contest/1976/problem/B  
// Start: 5/30/2024, 5:38:14 PM
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
    ll n; cin >> n;
    vll a(n), b(n+1); cin >> a >> b;
    ll ops = 0;
    ll copyCost = INT_MAX;
    bool NotFoundOptimalCopyCost = true;
    for (ll i = 0; i < n; i++)
    {
        ops += (abs(a[i]-b[i]));
        if (NotFoundOptimalCopyCost && ((min(a[i], b[i]) <= b[n] && max(a[i], b[i]) >= b[n]))) {
            copyCost = 1;
            NotFoundOptimalCopyCost = false;
        }
        if(NotFoundOptimalCopyCost) { 
            copyCost = min({copyCost, abs(b[n] - a[i])+1, abs(b[n]-b[i])+1});
        }
    }
    ops += copyCost;
    cout << ops << "\n";
}

/*
NOTES:
4 2 1 2
2 1 5 2 7

Copied 
-> in a or b = 1 
-> while adding or subtracting appears = 1
-> Min diffrence between any element of (a or b) and b[n] + 1

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