/*
    One day, I'm gonna grow wings
*/
// A. Lucky Sum
// URL: https://codeforces.com/contest/121/problem/A
// Time: 10/24/2025, 4:46:17 PM
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

// generate lucky numbers

vi luckey;
void generate(int n){
    if(n > 5e9) return;
    
    if(n > 0) luckey.push_back(n);
    generate(n * 10 + 4);
    generate(n * 10 + 7);
}

void solve() {
    int l, r; cin >> l >> r;

    generate(0);
    sort(all(luckey));    

    int cur = l;
    int sum = 0;
    for (int x : luckey) {
        if (cur > r) break;
        if (x < cur) continue;
        int upto = min(r, x);
        if (upto >= cur) sum += (upto - cur + 1) * x;
        cur = upto + 1;
    }
    cout << sum << "\n";
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