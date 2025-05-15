/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// B. The Picky Cat
// URL: https://codeforces.com/contest/2102/problem/B
// Time: 5/11/2025, 5:49:19 PM
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
    vi a(n); cin >> a;

    int x = abs(a[0]);

    for (int i = 0; i < n; i++){
        a[i] = abs(a[i]);
    }

    sort(all(a));

    int j = lower_bound(all(a), x) - a.begin();

    int after = n - j - 1; 
    // cout << after << " " << n / 2 << "\n";
    if((j == n / 2) || after >= n/2) cout << "YES\n";
    else cout << "NO\n"; 
    
}

/*
NOTES:
can we put n / 2 elements before it ???

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}