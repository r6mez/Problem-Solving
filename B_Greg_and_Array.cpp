// ﷽
// problem: B. Greg and Array
// URL: https://codeforces.com/group/isP4JMZTix/contest/386415/problem/B  
// Start: 4/26/2024, 4:29:59 AM
#include <iostream>
using namespace std;
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vll vector<long long>


/* NOT SOLVED */
void solve() {
    ll n, m, k; cin >> n >> m >> k;
    ll a[n];
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll op[m+1][3];
    for (ll i = 1; i <= m; i++) {
        cin >> op[i][0] >> op[i][1] >> op[i][2];
    }

    ll add[n] = {0};
    while(k--){
        ll x, y; cin >> x >> y;
        add[x-1]++;
        add[y]--;
    }

    for (ll i = 1; i <= m; i++) {
        add[i] += add[i-1];
    }

    for (ll i = 1; i <= m; i++) {
        ll l = op[i][0]-1, r = op[i][1]-1, val = op[i][2];
        a[l] += (val * add[i]);
        if(r+1 < n) a[r+1] -= (val * add[i]);
    }

    for (ll i = 1; i < n; i++) {
        a[i] += a[i-1];
    }

    for (ll i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}