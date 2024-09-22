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

void solve() {
    ll n, m, k; cin >> n >> m >> k;
    ll a[n];
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll op[m][3];
    for (ll i = 0; i < m; i++) {
        cin >> op[i][0] >> op[i][1] >> op[i][2];
    }



    ll xy[m + 1] = { 0 };
    for (int i = 0; i < k; i++) {
        ll x, y;
        cin >> x >> y;
        xy[x - 1]++;
        if (y < m) xy[y]--; 
    }

    ll add[n + 1] = { 0 }; 
    for (int i = 0; i < m; i++) {
        xy[i + 1] += xy[i];
        
        add[op[i][0] - 1] += op[i][2] * xy[i];
        if (op[i][1] < n) add[op[i][1]] -= op[i][2] * xy[i]; 
    }


    for (ll i = 0; i < n; i++) {
        add[i + 1] += add[i];
        a[i] += add[i];
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