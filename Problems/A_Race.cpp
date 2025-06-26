/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// A. Race
// URL: https://codeforces.com/contest/2112/problem/A
// Time: 6/23/2025, 5:38:24 PM
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
    int a, x, y; cin >> a >> x >> y;
    for (int i = min(x, y); i <= max(x, y); i++){
        if(abs(x - i) < abs(x - a) && abs(y - i) < abs(y - a)) {
            cout << "YES\n";
            return;
        }
    }
    
    cout << "NO\n";
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