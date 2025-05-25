/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// A. Fashionable Array
// URL: https://codeforces.com/contest/2110/problem/0
// Time: 5/24/2025, 5:36:43 PM
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

    sort(all(a));

    int s = 0;
    for (int i = 0; i < n; i++){
        if(a[i]%2 == a.back()%2) break;
        s++;
    }

    int e = 0;
    for (int i = n - 1; i >= 0; i--){
        if(a[0]%2 == a[i]%2) break;
        e++;
    }

    cout << min(s, e) << "\n";
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