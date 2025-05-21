/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// H. Even Odd Sum
// URL: https://codeforces.com/group/Rilx5irOux/contest/607176/problem/H
// Time: 5/21/2025, 7:01:43 PM
#include <bits/stdc++.h>
using namespace std;
#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("evenodd.in", "r", stdin); }
const int MOD = 1000000007;

void Ramez() {
    int n; cin >> n;
    vi a(n + 1); 
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    

    int ans = 0;
    int cnt[2] = { 1, 0 }; 
    int p = 0;  // prefix parity        

    for (int i = 1; i <= n; ++i) {
        p = (p + (a[i] % 2)) % 2;
        int Bi = (p + (i % 2)) % 2;
        ans += cnt[Bi];
        cnt[Bi]++;
    }

    cout << ans << "\n";
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