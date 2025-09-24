/*
    One day, I'm gonna grow wings
*/
// E. Mexification
// URL: https://codeforces.com/contest/2137/problem/E
// Time: 9/7/2025, 7:04:34 PM
#include <bits/stdc++.h>
using namespace std;
#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { cin.tie(nullptr)->sync_with_stdio(false); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007;

void solve() {
    int n, k; cin >> n >> k;
    vi a(n); cin >> a;

    vi b = a, c;

    for (int i = 0; i < k; ++i) {
        if(k > 1){
            c = b;
            b = a;
        }

        vi cnt(n + 1);
        for (int x : a) cnt[x]++;

        int mex = 0;
        while (cnt[mex]) mex++;

        for (int i = 0; i < n; ++i) {
            if (cnt[a[i]] != 1 || a[i] > mex) 
                a[i] = mex;
        }
    
        // cout << a << "\n";

        if(k > 1 && k%2 != i%2){
            if(a == c) break;
        }
    }

    int ans = accumulate(all(a), 0LL);
    cout << ans << '\n';
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