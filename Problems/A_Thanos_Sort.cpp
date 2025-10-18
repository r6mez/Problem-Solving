/*
    One day, I'm gonna grow wings
*/
// A. Thanos Sort
// URL: https://codeforces.com/problemset/problem/1145/A
// Time: 10/9/2025, 9:59:56 PM
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

int n;
vi a;

bool isSorted(int l, int r) {
    for (int i = l; i < r; i++) {
        if (a[i] > a[i + 1]) return false;
    }
    return true;
}

int calc(int l, int r) {
    if (isSorted(l, r)) {
        return r - l + 1;
    }

    int mid = (l + r) / 2;

    return max(calc(l, mid), calc(mid + 1, r));
}

/*
8
7
0 + (0 + 7)/2 = 3
7 - (0 + 7)/2 = 4
*/

void solve() {
    cin >> n;
    a.resize(n);
    cin >> a;

    cout << calc(0, n - 1);
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