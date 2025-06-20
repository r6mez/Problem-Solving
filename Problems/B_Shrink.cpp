/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// B. Shrink
// URL: https://codeforces.com/contest/2117/problem/B
// Time: 6/8/2025, 5:40:15 PM
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
    vi a(n); 
    int l = 0, r = n - 1;
    int cnt = 1;
    while(l <= r){
        a[l++] = cnt++;
        if(r > l) a[r--] = cnt++;
    }
    cout << a << "\n";
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