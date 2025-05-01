/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// C. Neo's Escape
// URL: https://codeforces.com/contest/2108/problem/C
// Time: 5/1/2025, 6:46:59 PM
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
    
    int res = 0;
    for (int i = 0; i < n; i++) {
        int j = i;
        // 1
        while (j < n && a[j] >= a[max(0LL, j - 1)]) {
            j++;
        }
        --j;
        int k = j + 1;
        while (k < n && a[k] <= a[max(0LL, k - 1)]) {
            k++;
        }
        --k;
        //cout << i << " " << j << " " << k << endl;
        res++;
        i = max(j + 1, k);
        //i=j+1;
    }
    cout << res << endl;
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