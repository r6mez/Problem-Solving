/*
    One day, I'm gonna grow wings
*/
// B. Alternating Series
// URL: https://codeforces.com/contest/2131/problem/B
// Time: 8/13/2025, 7:31:39 PM
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
    
    vi a(n, -1);
    for (int i = 1; i < n; i += 2) {
        if(i != n - 1) a[i] = 3;
        else a[i] = 2;
    }
    cout << a << "\n";
}

/*
-1 3 -1 3 -1
*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}