/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// E. Sponsor of Your Problems
// URL: https://codeforces.com/contest/2121/problem/E
// Time: 6/18/2025, 7:39:39 PM
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

string L, R;
int n;

// memo[pos][tightLow][tightHigh]
int memo[20][2][2];

int digitDP(int pos, bool tightLow, bool tightHigh) {
    if (pos == n) return 0;

    int& res = memo[pos][tightLow][tightHigh];
    if (res != -1) return res;
    res = INT_MAX;

    int low = tightLow ? (L[pos] - '0') : 0;
    int high = tightHigh ? (R[pos] - '0') : 9;
    
    for (int d = low; d <= high; ++d) {
        bool nextTightLow = tightLow && (d == low);
        bool nextTightHigh = tightHigh && (d == high);
        
        int cost = 0;
        if (tightLow && d == (L[pos] - '0')) cost++;
        if (tightHigh && d == (R[pos] - '0')) cost++;
        
        res = min(res, cost + digitDP(pos + 1, nextTightLow, nextTightHigh));
    }

    return res;
}

void Ramez() {
    cin >> L >> R;
    n = L.size();
    memset(memo, -1, sizeof(memo));
    cout << digitDP(0, true, true) << '\n';
}

/*
NOTES:
199 201

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}