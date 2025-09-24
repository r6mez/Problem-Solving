/*
    One day, I'm gonna grow wings
*/
// A. All Lengths Subtraction
// URL: https://codeforces.com/contest/2143/problem/0
// Time: 9/17/2025, 5:38:11 PM
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

    if(n <= 2){
        cout << "YES\n";
        return;
    }

    int cntTops = 0, cntBottoms = 0;
    for (int i = 1; i < n - 1; i++){
        if(a[i-1] < a[i] && a[i] > a[i+1]) cntTops++;
        if(a[i-1] > a[i] && a[i] < a[i+1]) cntBottoms++;
    }

    int sorted = false;
    int reverseSorted = false;
    vi b(a);
    sort(all(b));
    if(a == b) sorted = true;
    reverse(all(b));
    if(a == b) reverseSorted = true;

    if((cntTops == 1 && cntBottoms == 0) || sorted || reverseSorted) cout << "YES\n";
    else cout << "NO\n";
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