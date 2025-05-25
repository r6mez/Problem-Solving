/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// E. Tufurama
// URL: https://codeforces.com/contest/961/problem/E
// Time: 5/23/2025, 10:51:12 PM
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

struct FenwickPURQ {
    int n;
    vi f;
    FenwickPURQ(int _n) : n(_n), f(n + 1, 0) {}

    // update
    void update(int idx, int val) {
        for (; idx <= n; idx += idx & -idx)
            f[idx] += val;
    }

    // queary
    int prefix(int idx) {
        int res = 0;
        for (; idx > 0; idx -= idx & -idx)
            res += f[idx];
        return res;
    }

    int rangeQuery(int l, int r) {
        return prefix(r) - prefix(l - 1);
    }
};

void Ramez() {
    int n; cin >> n;
    vi a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = min(a[i], n);
    }

    vector<vi> byEp(n + 1);
    for (int j = 1; j <= n; j++) {
        byEp[a[j]].push_back(j);
    }


    FenwickPURQ t(n + 1);

    int cnt = 0, epi = n;
    for (int x = n; x >= 1; x--) {
        while (epi >= x) {
            for (int j : byEp[epi]) {
                t.update(j, 1);
            }
            --epi;
        }

        if (a[x] > x) {
            cnt += t.rangeQuery(x + 1, a[x]);
        }
    }

    cout << cnt;
}

/*
NOTES:
for each i
check how many a[j]'s are there such that i <= a[j] && j > i

8 12 7
1: 1 -> 8
2: 1 -> 12
we can only access first n episod of every season


*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}