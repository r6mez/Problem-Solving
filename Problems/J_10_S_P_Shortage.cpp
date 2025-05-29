/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// J. 10 S.P Shortage
// URL: https://codeforces.com/group/Rilx5irOux/contest/608858/problem/J
// Time: 5/29/2025, 3:40:03 PM
#include <bits/stdc++.h>
using namespace std;
#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("short.in", "r", stdin); }
const int MOD = 1000000007;

void Ramez() {
    int a, b, c; cin >> a >> b >> c;

    int use111 = min({a, b, c});
    int rides = use111;

    a -= use111; b -= use111; c -= use111;

    int use305 = min(c, a / 3);
    rides += use305;
    
    a -= use305 * 3;

    rides += (5 * a + 10 * b) / 40;

    cout << rides << "\n";
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