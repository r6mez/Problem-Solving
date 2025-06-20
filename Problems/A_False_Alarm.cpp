/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// A. False Alarm
// URL: https://codeforces.com/contest/2117/problem/0
// Time: 6/8/2025, 5:36:35 PM
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

    int first = -1, last = -1;
    for (int i = 0; i < n; i++){
        if(first == -1 && a[i] == 1) first = i;
        if(a[i] == 1) last = i;
    }

    
    if(last - first + 1 <= k) cout << "YES\n";
    else cout << "NO\n";
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