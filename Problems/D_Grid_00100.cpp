/*
    I thought I could bring an end to the world's suffering,
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// D. Grid-00100
// URL: https://codeforces.com/problemset/problem/1371/D
// Time: 4/22/2025, 6:51:19 PM
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
    int n, k; cin >> n >> k;
    vector<vi> a(n, vi(n, 0));
    int q = k / n, r = k % n;
    for (int shift = 0; shift < q; ++shift) {
        for (int i = 0; i < n; ++i) {
            a[i][(i + shift) % n] = 1;
        }
    }
    for (int i = 0; i < r; ++i) {
        a[i][(i + q) % n] = 1;
    }

    int f = (r == 0 ? 0 : 2);
    cout << f << '\n';
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j];
        }
        cout << '\n';
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