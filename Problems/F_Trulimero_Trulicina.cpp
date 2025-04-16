/*
    I thought I could bring an end to the world's suffering,
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// F. Trulimero Trulicina
// URL: https://codeforces.com/contest/2094/problem/F
// Time: 4/13/2025, 6:36:18 PM
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
    int n, m, k; cin >> n >> m >> k;
 
    if (m % k == 0) {
        for (int i = 0; i < n; i++) {
            int cur = i;
            for (int j = 0; j < m; j++) {
                cout << cur % k + 1 << ' ';
                cur++;
            }
            cout << '\n';
        }
    } else {
        int cur = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << cur % k + 1 << ' ';
                cur++;
            }
            cout << '\n';
        }
    }
}

/*
NOTES:
1 2 3 4
5 6 2 3
4 5 6 1



*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}