/*
    One day, I'm gonna grow wings
*/
// B. Discounts
// URL: https://codeforces.com/contest/2143/problem/B
// Time: 9/17/2025, 5:52:31 PM
#include <bits/stdc++.h>
using namespace std;
#define int         long long
#define vi          vector<int>
#define pii         pair<int, int>
#define all(v)      v.begin(), v.end()
#define finish(s)   { cout << s << "\n"; return; }
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { cin.tie(nullptr)->sync_with_stdio(false); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007, INF = 2e18;

void solve() {
    int n, k; cin >> n >> k;
    vi a(n); cin >> a;
    vi dis(k); cin >> dis;
    sort(all(a), greater<int>());
    sort(all(dis));

    vi pre(n);
    partial_sum(all(a), pre.begin());

    int cost = 0, j = 0;
    for (int i = 0; i < n; i++){
        if(j < k){
            int r = i + dis[j] - 2;
            if(r >= n) {
                cost += a[i];
                continue;
            }
            int l = i;
            cost += (r >= 0? pre[r] : 0) - (l ? pre[l - 1] : 0);
            i += dis[j] - 1;
            j++;
        } else {
            cost += a[i];
        }
    }
    
    cout << cost << "\n";
}

/*

*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}