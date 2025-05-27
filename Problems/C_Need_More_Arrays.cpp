/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// C. Need More Arrays
// URL: https://codeforces.com/contest/2114/problem/C
// Time: 5/26/2025, 6:16:19 PM
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
    int cnt = 1;
    int i = 0, j = 1;
    while (i < n && j < n){
        while(j < n && a[j] - a[i] <= 1) j++;
        if(j >= n) break;
        if(a[j] - a[i] <= 1) break;
        cnt++;
        i = j;
        j++;
    }
    
    cout << cnt << "\n";
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