/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// B. Sasha and the Apartment Purchase
// URL: https://codeforces.com/contest/2098/problem/B
// Time: 6/2/2025, 1:42:26 PM
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
    vi a(n); cin >> a;
    sort(all(a));
    int m = n - k;
    
    if (m == 0) {
        cout << 0 << endl;
        return;
    }
    
    int L = (m - 1) / 2;
    int R = (n - 1) - (m - 1) / 2;
    cout << a[R] - a[L] + 1 << endl;
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