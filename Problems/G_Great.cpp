/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// G. Great
// URL: https://codeforces.com/group/Rilx5irOux/contest/467645/problem/G
// Time: 7/12/2025, 6:19:11 PM
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
    int n, k; cin >> n >> k;
    int p = n / k; 
    int cnt = p * (n + 1) - k * (p * (p + 1) / 2);
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