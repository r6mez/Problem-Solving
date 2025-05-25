/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// B - P(X or Y)
// URL: https://atcoder.jp/contests/abc407/tasks/abc407_b
// Time: 5/24/2025, 3:01:44 PM
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
    int x, y; cin >> x >> y;
    double cnt = 0;
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            if(j + i >= x || abs(i - j) >= y) cnt++;
        }
    }

    double prob = cnt/36.0;
    cout << fixed << setprecision(10) << prob;
}

/*
NOTES:

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}