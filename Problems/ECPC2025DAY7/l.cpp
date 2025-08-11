#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define all(v) v.begin(),v.end()

void solve() {
    int n, k; cin >> n >> k;
    vi a(n); for(auto &i : a) cin >> i;
    
    int cnt = 0;
    set<int> s;
    for (int i = 0; i < n; i++){
        if(s.find(k - a[i]) == s.end()){
            s.insert(a[i]);
        } else {
            cnt++;
            s.clear();
        }
    }
    cout << cnt << "\n";
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