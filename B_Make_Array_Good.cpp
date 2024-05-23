// ﷽
// problem: B. Make Array Good
// URL: https://codeforces.com/problemset/problem/1762/B  
// Start: 5/23/2024, 8:00:16 PM
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

ll f(ll x){
    ll cur=1;
    while(cur<=x){
        cur*=2;
    }
    return cur;
}
void solve(){
    ll n; cin>>n;
    cout<<n<<"\n";
    for(ll i=1;i<=n;i++){
        ll x; cin>>x;
        cout<<i<<" "<<f(x)-x<<"\n";
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