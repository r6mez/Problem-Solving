/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// E. Mashup Moments
// URL: https://codeforces.com/group/Rilx5irOux/contest/620530/problem/E
// Time: 7/18/2025, 5:39:56 PM
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
    int n, q, m; cin >> n >> q >> m;
    vi a(n); cin >> a;
    vector<string> s(n); cin >> s;
    while(q--){
        int x; cin >> x;
        int i = upper_bound(all(a), x) - a.begin() - 1;
        cout << s[i] << "\n";
    }
}

/*
NOTES:

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}