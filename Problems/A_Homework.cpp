/*
    One day, I'm gonna grow wings
*/
// A. Homework
// URL: https://codeforces.com/contest/2132/problem/0
// Time: 8/21/2025, 5:37:16 PM
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
    string a; cin >> a;
    int m; cin >> m;
    string b, c; cin >> b >> c;
    string pre = "";
    for (int i = m - 1; i >= 0; i--){
        if(c[i] == 'V'){
            pre.push_back(b[i]);
        }
    }

    string suf = "";
    for (int i = 0; i < m; i++){
        if(c[i] == 'D'){
            suf.push_back(b[i]);
        }       
    }
    
    string res = pre + a + suf;
    cout << res << "\n";
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