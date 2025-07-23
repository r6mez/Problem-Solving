/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// B. Two Tables
// URL: https://codeforces.com/contest/1555/problem/B
// Time: 7/16/2025, 12:31:45 PM
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
    int W, H; cin >> W >> H;
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    int w1 = x2 - x1, h1 = y2 - y1;
    int w2, h2; cin >> w2 >> h2;

    if (w1 + w2 > W && h1 + h2 > H) {
        cout << "-1\n";
        return;
    }

    int left = x1, right = W - x2;
    int bottom = y1, top = H - y2;

    int moveX = INT_MAX, moveY = INT_MAX;
    if (w1 + w2 <= W) moveX = max(0LL, w2 - max(left, right));
    if (h1 + h2 <= H) moveY = max(0LL, h2 - max(bottom, top));
    double answer = min(moveX, moveY);
    cout << setprecision(9) << fixed << answer << "\n";
}

/*
NOTES:

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}