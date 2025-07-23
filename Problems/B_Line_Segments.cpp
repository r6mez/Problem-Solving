/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// B. Line Segments
// URL: https://codeforces.com/contest/2119/problem/B
// Time: 7/5/2025, 5:42:39 PM
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
    int n; cin >> n;
    int px, py, qx, qy; cin >> px >> py >> qx >> qy;    
    vi a(n); cin >> a;

    int sum = accumulate(all(a), 0LL), maxElement = *max_element(all(a));
    int d = (px - qx) * (px - qx) + (py - qy) * (py - qy);

    int mn = max(0LL, maxElement - (sum - maxElement));

    if (mn * mn <= d && d <= sum * sum) cout << "Yes\n";
    else cout << "No\n";
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