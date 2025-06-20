/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// D. Creating a Schedule
// URL: https://codeforces.com/contest/2111/problem/D
// Time: 6/5/2025, 8:38:58 PM
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
    int n, m; cin >> n >> m;
    vi cr(m); cin >> cr;
    
    sort(all(cr));
    
    int l = 0, r = m - 1;
    vector<vi> table(n, vi(6));

    for (int i = 0; i < n - 1; i += 2){
        for (int j = 0; j < 6; j++){
            if(j&1) table[i][j] = cr[l], table[i + 1][j] = cr[r];
            else table[i][j] = cr[r], table[i + 1][j] = cr[l];
        }
        l++, r--;
    }
    
    if(n&1){
        for (int j = 0; j < 6; j++){
            if(j&1) table[n - 1][j] = cr[l];
            else table[n - 1][j] = cr[r];
        }
    }

    for(vi row : table){
        cout << row << "\n";
    }
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