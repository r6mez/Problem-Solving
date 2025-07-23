/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// D1. Balance (Easy version)
// URL: https://codeforces.com/problemset/problem/1732/D1
// Time: 7/16/2025, 1:10:47 PM
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
    int q; cin >> q;
    set<int> s;
    map<int, int> m;
    while (q--) {
        char ops; cin >> ops;
        if (ops == '+') {
            int x; cin >> x;
            s.insert(x);

            int k = 2 * x;
            while (s.find(k) != s.end()) k += x;
            m[x] = k;
        }
        else {
            int k; cin >> k;
            if (s.find(k) == s.end()) cout << k << "\n";
            else {
                while(s.count(m[k])) m[k] += k;
                cout << m[k] << "\n";
            }
        }
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