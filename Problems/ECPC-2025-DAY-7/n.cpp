#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define all(v) v.begin(),v.end()

void solve() {
    int n, k; cin >> n >> k;
    vi wights(10); for(auto &i : wights) cin >> i;
    vi sum(n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 10; j++){
            int x; cin >> x;
            sum[i] += x * wights[j];
        }   
    }
    sort(sum.rbegin(), sum.rend());

    int total = accumulate(sum.begin(), sum.begin() + k, 0LL);
    cout << total << "\n";
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