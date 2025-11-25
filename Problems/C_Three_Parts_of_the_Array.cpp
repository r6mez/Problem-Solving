/*
    One day, I'm gonna grow wings
*/
// C. Three Parts of the Array
// URL: https://codeforces.com/problemset/problem/1006/C
// Time: 10/31/2025, 11:37:25 AM
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
    int n; cin >> n;
    vi arr(n + 1), pref(n + 1);
 
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + arr[i];
 
    map<int,int> cnt;

    for(int i = 1; i <= n - 1; i++) cnt[pref[i]]++;
    int total = pref[n], ans = 0;

    for(int a = 1; a <= n; a++){
        int target = total - pref[a];
        if(cnt[target] > 0) ans = max(ans, pref[a]);
        cnt[pref[a]]--;
    }
   
    cout << ans << "\n";
}

/*

*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) solve();
}