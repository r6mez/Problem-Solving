/*
    One day, I'm gonna grow wings
*/
// A. Lever
// URL: https://codeforces.com/contest/2131/problem/A
// Time: 8/13/2025, 7:27:09 PM
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
    int n; cin >> n;
    vi a(n), b(n); cin >> a >> b;
    int cnt = 0;
    for (int i = 0; i < n; i++){
        if(a[i] > b[i]) cnt += (a[i] - b[i]);
    }
    cout << cnt + 1 << "\n";
}

/*

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}