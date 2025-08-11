#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define all(v) v.begin(),v.end()

void solve() {
    int n; cin >> n;
    vector<int> cnt(n + 1, 0);
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        cnt[x]++;
    }

    int answer = 0;

    for (int d = 1; d <= n; d <<= 1) {
        for (int t = 1; ; t++) {
            int evenVal = d * (2 * t);
            int oddVal = d * (2 * t + 1);
            if (oddVal > n) break;
            answer += cnt[evenVal] * cnt[oddVal];
        }
    }

    cout << answer << "\n";
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t = 1;
    cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}