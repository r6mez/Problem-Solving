/*
    One day, I'm gonna grow wings
*/
// Tower of Hanoi
// URL: https://cses.fi/problemset/task/2165
// Time: 10/10/2025, 4:05:40 PM
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

vector<pii> mv;

void moveDisks(int n, int a, int b, int c) {
    if (n == 1) {
        mv.push_back({a, c});
        return;
    }

    moveDisks(n - 1, a, b, c);
    mv.push_back({a, b});
    moveDisks(n - 1, c, a, b);
}


void solve() {
    int n; cin >> n;
    moveDisks(n, 1, 3, 2);
    cout << mv.size() << "\n";
    for (auto& [a, c] : mv) {
        cout << a << " " << c << "\n";
    }
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