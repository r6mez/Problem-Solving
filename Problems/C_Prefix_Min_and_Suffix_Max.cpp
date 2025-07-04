/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// C. Prefix Min and Suffix Max
// URL: https://codeforces.com/contest/2123/problem/C
// Time: 7/1/2025, 5:54:24 PM
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
    
    string s(n, '0');
    
    int mn = min_element(all(a)) - a.begin();
    int mx = max_element(all(a)) - a.begin();
    s[0] = '1';
    s[n - 1] = '1';
    s[mn] = '1';
    s[mx] = '1';

    vi pre(n), suf(n);
    pre[0] = a[0];
    suf[n - 1] = a[n - 1];
    
    for (int i = 1; i < n; i++){
        pre[i] = min(pre[i - 1], a[i]);
    }

    for (int i = n - 2; i >= 0; i--){
        suf[i] = max(suf[i + 1], a[i]);
    }
    
    for (int i = 0; i < n; i++){
        if(suf[i] == a[i] || pre[i] == a[i]) s[i] = '1';
    }
    
    // cout << a << "\n" << pre << "\n" << suf << "\n";
    
    cout << s << "\n";
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