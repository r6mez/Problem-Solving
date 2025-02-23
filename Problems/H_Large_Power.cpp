/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all that remained were fields of dreamless solitude.
*/
// H. Large Power
// URL: https://codeforces.com/group/6aLUitEJUs/contest/590165/problem/H
// Time: 2/21/2025, 10:03:44 PM
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
    int x, y;
    cin >> x >> y;
    if (y == 0) {
      cout << 1 << "\n";
      return;
    }
   
    long double lx = (long double)x;
    long double value = y * log10l(lx);
   
    long double eps = 1e-12;
    long long ans = (int)(floor(value + eps)) + 1;
   
    cout << ans << "\n";
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

