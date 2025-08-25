/*
    One day, I'm gonna grow wings
*/
// A. Redstone?
// URL: https://codeforces.com/contest/2133/problem/A
// Time: 8/24/2025, 9:30:20 PM
#include <bits/stdc++.h>
using namespace std;
#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> auto& operator<<(auto& o, vector<T>& v) { for (auto& e : v) o << e << ' '; return o; }
template<typename T> auto& operator>>(auto& i, vector<T>& v) { for (auto& e : v) i >> e; return i; }
void FastIO() { cin.tie(nullptr)->sync_with_stdio(false); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007;

void solve() {
    int n; cin >> n;
    vi a(n); cin >> a;
    sort(all(a)); 
    for (int i = 0; i < n - 1; i++){
        if(a[i] == a[i + 1]){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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