/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// F. Yamakasi
// URL: https://codeforces.com/contest/2121/problem/F
// Time: 6/17/2025, 6:55:58 PM
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
    int n, s, x; cin >> n >> s >> x;
    vi a(n); cin >> a;

    int cnt1 = 0, cnt2 = 0;

    map<int, int> cntPre1, cntPre2;
    cntPre1[0] = 1; cntPre2[0] = 1;
    int pre1 = 0, pre2 = 0;
    for (int ai : a) {
        if (ai <= x) {
            pre1 += ai;
            if (cntPre1.find(pre1 - s) != cntPre1.end()) cnt1 += cntPre1[pre1 - s];
            cntPre1[pre1]++;
        }
        else {
            cntPre1.clear(); pre1 = 0;
            cntPre1[0] = 1;
        }

        if (ai <= x - 1) {
            pre2 += ai;
            if (cntPre2.find(pre2 - s) != cntPre2.end()) cnt2 += cntPre2[pre2 - s];
            cntPre2[pre2]++;
        }
        else {
            cntPre2.clear(); pre2 = 0;
            cntPre2[0] = 1;
        }
    }

    int total = cnt1 - cnt2;
    cout << total << '\n';
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