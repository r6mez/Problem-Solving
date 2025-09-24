/*
    One day, I'm gonna grow wings
*/
// B. Maximum Cost Permutation
// URL: https://codeforces.com/contest/2144/problem/B
// Time: 9/15/2025, 5:50:27 PM
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

    set<int> s(all(a));
    vi missing;
    for (int i = 1; i <= n; i++){
        if(s.find(i) == s.end()) missing.push_back(i);
    }
    
    for (int i = 0; i < n; i++){
        if(a[i] == 0) {
            a[i] = missing.back();
            missing.pop_back();
        }
    }

    int sorted = 0;
    for (int i = 0; i < n; i++){
        if(i + 1 == a[i]) sorted++, a[i] = 0;
        else break;
    }

    for (int i = n - 1; i >= 0; i--){
        if(i + 1 == a[i]) sorted++;
        else break;
    }
    
    cout << n - sorted << "\n";
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