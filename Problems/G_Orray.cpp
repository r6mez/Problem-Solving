/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// G. Orray
// URL: https://codeforces.com/problemset/problem/1742/G
// Time: 5/18/2025, 4:01:02 PM
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

    int prefixOR = 0;
    for (int i = 0; i < 32; ++i) {
        int idx = 0, mx = 0;
        for (int j = 0; j < n; ++j) {
            if (a[j] == -1) continue;

            if ((prefixOR | a[j]) > mx){
                mx = prefixOR | a[j];
                idx = j;
            }
        }

        if (mx <= prefixOR) break;

        cout << a[idx] << ' ';
        a[idx] = -1;
        prefixOR = mx;
    }

    for (int i = 0; i < n; ++i) {
        if (a[i] != -1){
            cout << a[i] << ' ';
        }
    }

    cout << '\n';
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