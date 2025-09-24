/*
    One day, I'm gonna grow wings
*/
// A. Cut the Array
// URL: https://codeforces.com/contest/2144/problem/A
// Time: 9/15/2025, 5:38:11 PM
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
    vi a(n); cin >> a;
    vi pre(n), suf(n);
    pre[0] = a[0];
    for (int i = 1; i < n; i++){
        pre[i] = pre[i - 1] + a[i];
    }
    
    suf[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--){
        suf[i] = suf[i + 1] + a[i];
    }
    
    for (int l = 0; l < n - 2; l++){
        for (int r = l + 1; r < n - 1; r++){
            int s1 = pre[l] % 3;
            int s2 = (pre[r] - pre[l]) % 3;
            int s3 = suf[r + 1] % 3;

            if(s1 == s2 && s2 == s3){
                cout << l + 1 << " " << r + 1 << "\n";
                return;
            }

            if(s1 != s2 && s2 != s3 && s1 != s3){
                cout << l + 1 << " " << r + 1 << "\n";
                return;
            }
        }
    }
    
    cout << "0 0\n";
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