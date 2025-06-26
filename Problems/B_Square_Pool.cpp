/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// B. Square Pool
// URL: https://codeforces.com/contest/2120/problem/B
// Time: 6/21/2025, 5:52:06 PM
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
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int dx, dy, x, y; cin >> dx >> dy >> x >> y;
        if(((x * dx) % s + s)%s == ((y * dy) % s + s)%s) cnt++;
    }
    cout << cnt << "\n";
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