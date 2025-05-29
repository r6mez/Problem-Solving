/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// L. Aya in KPT
// URL: https://codeforces.com/group/Rilx5irOux/contest/608858/problem/L
// Time: 5/29/2025, 2:49:44 PM
#include <bits/stdc++.h>
using namespace std;
#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("kpt.in", "r", stdin); }
const int MOD = 1000000007;

void Ramez() {
    double a, b, c, d; cin >> a >> b >> c >> d;
    double x = a/b + c/d, y = (a/b)* (c/d);
    if(x > y) cout << ">";
    else if (x < y) cout << "<";
    else cout << "=";
    cout << "\n";
}

/*
NOTES:

*/

int32_t main() {
    UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}