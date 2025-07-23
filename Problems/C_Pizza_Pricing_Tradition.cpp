/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// C. Pizza Pricing Tradition
// URL: https://codeforces.com/group/Rilx5irOux/contest/620530/problem/C
// Time: 7/18/2025, 5:51:10 PM
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
    int r, s, x; cin >> r >> s >> x;
    int newPrice = ceil( (double)x * s * s / (r * r) );
    int rem = newPrice % 10;
    if(rem) newPrice += (10 - rem);
    cout << newPrice << "\n";
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