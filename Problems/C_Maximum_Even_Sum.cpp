/*
    One day, I'm gonna grow wings
*/
// C. Maximum Even Sum
// URL: https://codeforces.com/contest/2137/problem/C
// Time: 9/7/2025, 6:16:37 PM
#include <bits/stdc++.h>
using namespace std;
#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { cin.tie(nullptr)->sync_with_stdio(false); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007;

void solve() {
    int a, b; cin >> a >> b;

    if ((a & 1) && (b & 1)) {
        cout << a * b + 1 << '\n';
        return;
    }

    int temp = b, cnt2 = 0;

    while (temp % 2 == 0) {
        cnt2++; temp /= 2;
    }

    if (cnt2 == 0 || (cnt2 == 1 && a % 2 == 1)) {
        cout << -1 << '\n';
        return;
    }

    cout << a * (b / 2) + 2 << '\n';
}

/*
1 8
4: 4 2 = 6
8 = 8 1 = 9 (not even)

1 6
1: 1 6 = 7 (not even)
2: 2 3 = 5 (not even)
3: 3 2 = 5 (not even)
6: 6 1 = 7 (not even)
*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}