/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// B. Codeforces Subsequences
// URL: https://codeforces.com/problemset/problem/1368/B
// Time: 6/7/2025, 12:28:05 PM
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
    
    // c o d e f o r c e s
    int sub = 1;
    vi freq(10, 1);
    while (sub < n) {
        for (int i = 0; i < 10; ++i) {
            if (sub >= n) break;
            else {
                sub /= freq[i];
                sub *= ++freq[i];
            }

            if (sub >= n) break;
        }
    }

    string ans = "codeforces";
    for (int i = 0; i < 10; ++i) {
        while (freq[i]--) cout << ans[i];
    }
}

/*
NOTES:

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}