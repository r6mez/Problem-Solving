/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// B. Hossam and Friends
// URL: https://codeforces.com/problemset/problem/1771/B
// Time: 5/14/2025, 6:41:28 PM
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
    int n, m; cin >> n >> m;
    vi farest(n, n);

    int ans = 0;
    for (int i = 0; i < m; ++i) {
        int x, y; cin >> x >> y;

        if (x > y)
            swap(x, y);
        
        farest[x - 1] = min(farest[x - 1], y - 1);
    }

    for (int i = n - 1; i >= 0; --i) {
        if (i != n - 1)
            farest[i] = min(farest[i], farest[i + 1]);
    
        ans += (farest[i] - i);
    }
    
    cout << ans << '\n';
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