/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// C. Tiles
// URL: https://codeforces.com/contest/1178/problem/C
// Time: 6/25/2025, 6:42:52 PM
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
const int MOD = 998244353;

int powmod(int a, int b, int m) {
    int result = 1;
    while (b > 0) {
        if (b & 1) result = (result * a) % m;
        a = (a * a) % m;
        b /= 2;
    }
    return result;
}

void Ramez() {
    int w, h; cin >> w >> h;
    int answer = (4 * powmod(2, w - 1, MOD) * powmod(2, h - 1, MOD))%MOD;
    cout << answer;
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