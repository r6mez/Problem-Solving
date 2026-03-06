#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define all(v) v.begin(),v.end()

void solve() {
    int n; cin >> n;
    vi a(n); for (int& x : a) cin >> x;

    int N = 1 << n;
    vector<int> xorVal(N, 0);
    for (int mask = 1; mask < N; mask++) {
        int value = 0;
        for (int i = 0; i < n; i++) {
            if ((1 << i) & mask) {
                value ^= a[i];
            }
        }
        xorVal[mask] = value;
    }


    vector<pair<int, int>> dp(N, { 0, 0 });
    for (int mask = 1; mask < N; mask++) {
        dp[mask] = { xorVal[mask], -1 };

        for (int sub = mask; sub; sub = (sub - 1) & mask) {
            int other = mask ^ sub;
            pair<int, int> divided = { dp[sub].first + xorVal[other], dp[sub].second - 1 };
            dp[mask] = max(dp[mask], divided);
        }
    }

    cout << dp[N - 1].first << " " << -dp[N - 1].second << "\n";
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