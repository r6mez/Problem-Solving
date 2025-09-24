/*
    One day, I'm gonna grow wings
*/
// C. Ultimate Value
// URL: https://codeforces.com/contest/2140/problem/C
// Time: 9/9/2025, 5:55:07 PM
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
const int MOD = 1000000007;

void solve() {
    int n; cin >> n;
    vi a(n); cin >> a;

    if (n == 1) finish(a[0]);

    int f = 0;
    for (int i = 0; i < n; ++i) {
        if ((i % 2) == 0) f += a[i];
        else f -= a[i];
    }

    int minEven = INT_MAX, maxOdd = -INT_MAX;
    int gain = 0;

    for (int r = 0; r < n; ++r) {
        if (r % 2 == 1) {
            gain = max(gain, (r + 2 * a[r]) - minEven);
            maxOdd = max(maxOdd, 2 * a[r] - r);
        } else {
            gain = max(gain, maxOdd - (2 * a[r] - r));
            minEven = min(minEven, 2 * a[r] + r);
        }
    }

    int op2 = f + gain;
    int op3 = f + ((n % 2 != 0) ? (n - 1) : (n - 2));

    int ans = max({ f, op2, op3 });

    finish(ans);
}

/*
bigger elements must be at odd indices
but swapping to achive this is reversable so, it doesn't matter
also bob can't do this forever as each swap increases the output

1 14 1 14 1 15
15 14 1 14 1 1
cost = -12 + 5 = -7

31 12 14 22 89 6 78 25 91
31 12 25 22 89 6 78 14 91
cost = 260 + 5 = 265

find maximum even (-)
and find minimum odd (+)
swap them and add the difference of i
but the distance needs to be as far as possible
*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}