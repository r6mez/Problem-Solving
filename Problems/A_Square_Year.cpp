/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// A. Square Year
// URL: https://codeforces.com/contest/2114/problem/0
// Time: 5/26/2025, 5:36:50 PM
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
    for (int i = 0; i * i <= n; i++){
        for (int j = 0; j * j <= n; j++){
            if((i + j) * (i + j) == n){
                cout << i << " " << j << "\n";
                return;
            }
        }
    }
    
    cout << "-1\n";
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