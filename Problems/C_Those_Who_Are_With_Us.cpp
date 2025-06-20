/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// C. Those Who Are With Us
// URL: https://codeforces.com/contest/2121/problem/C
// Time: 6/17/2025, 5:48:13 PM
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
    vector<vi> a(n, vi(m));
    int mx = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            mx = max(mx, a[i][j]);
        }
    }

    vector<vi> rows(n), cols(m);
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == mx) {
                rows[i].push_back(j);
                cols[j].push_back(i);
                cnt++;
            }
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            int total = rows[i].size() + cols[j].size() - (binary_search(all(rows[i]), j));
            if(total == cnt) {
                cout << mx - 1 << "\n";
                return;
            }
        }
    }
    
    cout << mx << "\n";
}

/*
NOTES:
0 0 5 0 0
0 0 5 0 0
5 5 5 5 5
0 0 5 0 0 
0 0 5 0 0 

1 3
2 3
3 3
4 3
5 3
3 1 
3 2 
3 3 
3 4
3 5
*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}