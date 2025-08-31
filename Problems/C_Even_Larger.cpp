/*
    One day, I'm gonna grow wings
*/
// C. Even Larger
// URL: https://codeforces.com/contest/2134/problem/C
// Time: 8/26/2025, 6:31:08 PM
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
    int n; cin >> n;
    vi a(n); cin >> a;

    int cnt = 0;
    for (int i = 1; i < n; i += 2) {
        if (i != n - 1 && a[i + 1] > a[i]) {
            cnt += a[i + 1] - a[i];
            a[i + 1] = a[i];
        }

        if (a[i - 1] > a[i]) {
            cnt += a[i - 1] - a[i];
            a[i - 1] = a[i];
        }
    }


    for (int i = 1; i < n; i += 2) {
        if (i == n - 1) continue;

        int diff = a[i + 1] + a[i - 1] - a[i];
        if(diff < 0) continue;

        cnt += diff;

        if (a[i + 1] - diff >= 0) {
            a[i + 1] -= diff;
        }
        else {
            diff -= a[i + 1];
            a[i + 1] = 0;
        }

        if (a[i - 1] - diff >= 0) {
            a[i - 1] -= diff;
        }
        else {
            diff -= a[i - 1];
            a[i - 1] = 0;
        }
    }

    cout << cnt << "\n";
}

/*
5
3 1 4 5 1
1 1 0 5 1 -6


11
3 0 5 4 4 5 3 0 3 4 1
0 0 0 4 4 5 3 0 3 4 1 -8
0 0 0 4 4 5 1 0 3 4 1 -2
0 0 0 4 4 5 0 0 0 4 1 -4
0 0 0 4 4 5 0 0 0 4 1

for even indices
remove from i + 1, i - 1 until i > sum of both

*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}