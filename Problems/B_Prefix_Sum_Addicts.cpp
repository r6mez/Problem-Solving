/*
    One day, I'm gonna grow wings
*/
// B. Prefix Sum Addicts
// URL: https://codeforces.com/contest/1738/problem/B
// Time: 10/16/2025, 8:35:35 PM
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
    vi a(k); cin >> a;

    if(k == 1){
        finish("Yes");
    }
    
    vi b;
    for (int i = k - 1; i >= 1; i--){
        b.push_back(a[i] - a[i - 1]);
    }
    reverse(all(b));
    
    if(!is_sorted(all(b)))
        finish("No");

    if (a[0] > b[0] * (n - k + 1)) finish("No");
    
    finish("Yes");
}

/*
5 2
5 6

1 1 1 1 1
*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}