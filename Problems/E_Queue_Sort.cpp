/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// E. Queue Sort
// URL: https://codeforces.com/problemset/problem/1899/E
// Time: 5/8/2025, 10:53:16 PM
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
    
    int mn = *min_element(all(a));
    for (int i = 0; i < n; ++i) {
        if (mn == a[i]){
            mn = i;
            break;
        }
    }
    
    vi v;
    for (int i = mn; i < n; ++i) {
        v.push_back(a[i]);
    }

    if (is_sorted(v.begin(), v.end())) cout << mn << endl;
    else cout << -1 << endl;
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