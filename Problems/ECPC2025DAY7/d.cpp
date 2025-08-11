#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define all(v) v.begin(),v.end()

void solve() {
    int h1, h2, h3; cin >> h1 >> h2 >> h3; 
    cout << max({h1, h2, h3});
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t = 1;
    //cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}