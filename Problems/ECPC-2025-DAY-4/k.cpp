#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define all(v) v.begin(),v.end()

void solve() {
    int n, x; cin >> n >> x;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] /= x;
    }

    int idxL = 0, idxR = -1, mn = a[0];
    for (int i = 0; i < n; i++) {
        if (mn > a[i]) {
            mn = a[i];
            idxL = i;
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        if (mn == a[i]) {
            idxR = i;
            break;
        }
    }

    int idx, cnt;
    if (mn % 2 == 0) {
        idx = idxL;
        cnt = mn * x * n + (idxL) * x;
    }
    else {
        idx = idxR;
        cnt = mn * x * n + (n - idxR - 1) * x;
    }

    cout << mn + 1 << " " << idx + 1 << " " << cnt << "\n";
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t = 1;
    // cin>>t;
    while (t--) solve();
    return 0;
}