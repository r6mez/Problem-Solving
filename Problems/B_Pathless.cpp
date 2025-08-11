/*
    I was alone in an empty universe.
    A universe too small and at the same time... too infinite.
*/
// B. Pathless
// URL: https://codeforces.com/contest/2130/problem/B
// Time: 7/31/2025, 6:17:47 PM
#include <bits/stdc++.h>
using namespace std;
#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007;


void Ramez() {
    int n, s; cin >> n >> s;
    vi a(n);
    int sum = 0, c0 = 0, c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 0) c0++;
        else if (a[i] == 1) c1++;
        else c2++;
        sum += a[i];
    }

    if (s < sum || s - sum == 1) {
        while(c0--) cout << 0 << ' ';
        while(c2--) cout << 2 << ' ';
        while(c1--) cout << 1 << ' ';
        cout << "\n";
    } else {
        cout << -1 << "\n";
    }
}

/*
s < n
*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}