/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// D. CDs
// URL: https://codeforces.com/group/3nQaj5GMG5/contest/374321/problem/D
// Time: 5/7/2025, 8:35:58 PM
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
    int x, y; cin >> x >> y;

    unordered_set<int> jack;
    int cd;

    for (int i = 0; i < x; i++) {
        cin >> cd;
        jack.emplace(cd);
    }

    int overlap = 0;

    for (int i = 0; i < y; i++) {
        cin >> cd;
        if (jack.count(cd)) overlap++;
    }

    cout << overlap << endl;
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