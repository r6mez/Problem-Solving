// B. Tony Stark
// URL: https://codeforces.com/group/Rilx5irOux/contest/678837/problem/B
// Time: 4/21/2026, 11:31:45 PM
#include <bits/stdc++.h>
#include <cmath>
#include <iomanip>
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

double PI = acos(-1);

double to_radian(double x){
    return x * PI / 180.0;
}

void solve() {
    double a, b, c, k; cin >> a >> b >> c >> k;

    double l = 0, r = 1e9;
    while (l + 1e-5 < r) {
        double radius = (l + r) / 2.0;
        double triangle_area = 2 * radius * radius * sin(to_radian(a)) * sin(to_radian(b)) * sin(to_radian(c));
        double circle_area = PI * radius * radius;
        if(circle_area - triangle_area <= k){
            l = radius;
        } else {
            r = radius;
        }
    }

    cout << fixed << setprecision(9) << l << "\n";
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