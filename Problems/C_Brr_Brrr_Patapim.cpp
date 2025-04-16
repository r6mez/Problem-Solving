/*
    I thought I could bring an end to the world's suffering,
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// C. Brr Brrr Patapim
// URL: https://codeforces.com/contest/2094/problem/C
// Time: 4/13/2025, 5:46:26 PM
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
    vector<vi> g(n, vi(n));
    for(vi &a : g) cin >> a;

    vi a(2 * n); 
    for (int i = 1; i < n; i++){
        a[i] = g[0][i - 1];
    }
    for (int i = 1; i <= n; i++){
        a[n - 1 + i] = g[n - 1][i - 1];
    }
    
    set<int> s(all(a));
    for (int i = 1; i <= 2*n; i++){
        if(s.find(i) == s.end()){
            a[0] = i;
            break;
        }
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