/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// E. Clock hands
// URL: https://codeforces.com/group/Rilx5irOux/contest/608858/problem/E
// Time: 5/29/2025, 2:54:32 PM
#include <bits/stdc++.h>
using namespace std;
#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("clock.in", "r", stdin);  }
const int MOD = 1000000007;

void Ramez() {
    int h1, m1, h2, m2; 
    char dummy;
    cin >> h1 >> dummy >> m1 >> h2 >> dummy >> m2;
    int start = h1 * 60 + m1, end = h2 * 60 + m2;
    int answer = 0;
    if (start <= end) answer += (end - start) * 6;
    else answer = (720 - start) * 6 + end * 6;
    cout << answer << "\n";
}

/*
NOTES:
11 -> 12 (1 hour)
11 -> 10 

*/

int32_t main() {
    UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}