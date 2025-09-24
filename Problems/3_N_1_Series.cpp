/*
    One day, I'm gonna grow wings
*/
// 3N+1 Series
// URL: https://vjudge.net/problem/Gym-324997A
// Time: 9/19/2025, 5:51:37 PM
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

int cnt = 0;

void calc(int n){
    cnt++;
    if(n == 1) return;
    if(n%2 == 0) calc(n/2);
    else calc(3 * n + 1);
}


void solve() {
    int n; cin >> n;
    calc(n);
    cout << cnt;
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