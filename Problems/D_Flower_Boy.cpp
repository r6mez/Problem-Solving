/*
    I thought I could bring an end to the world's suffering,
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// D. Flower Boy
// URL: https://codeforces.com/contest/2106/problem/D
// Time: 4/24/2025, 5:13:55 PM
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


// ربنا ياخد العيال بتاعت شات
void Ramez() {
    int n, m;
    cin >> n >> m;
    vector<long long> a(n), b(m);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;

    // 1) pref[i] = # of b’s matched in a[0..i-1]
    vector<int> pref(n+1, 0);
    for (int i = 0, j = 0; i < n; i++) {
        if (j < m && a[i] >= b[j]) ++j;
        pref[i+1] = j;
    }
    // if we can match all m without insertion
    if (pref[n] == m) {
        cout << 0 << "\n";
        return;
    }

    // 2) p0[j] = earliest p such that pref[p] == j
    vector<int> p0(m+1, -1);
    for (int p = 0; p <= n; p++) {
        int got = pref[p];
        if (got <= m && p0[got] == -1)
            p0[got] = p;
    }

    // 3) suff[i] = # of b’s matched from the end in a[i..n-1]
    vector<int> suff(n+1, 0);
    for (int i = n-1, t = 0; i >= 0; i--) {
        if (t < m && a[i] >= b[m-1 - t]) ++t;
        suff[i] = t;
    }

    // 4) for each j, find the latest r0 so that suff[r0] >= (m-j-1)
    auto find_r0 = [&](int need) {
        // suff is non-increasing in i, so binary search:
        int lo = 0, hi = n, best = -1;
        while (lo <= hi) {
            int mid = (lo+hi)/2;
            if (suff[mid] >= need) { best = mid; lo = mid+1; }
            else hi = mid-1;
        }
        return best;
    };

    long long answer = LLONG_MAX;
    for (int j = 0; j < m; j++) {
        if (p0[j] < 0) continue;               // can’t match the first j
        int need = m - j - 1;
        int r = find_r0(need);
        if (r >= p0[j]) {
            // we can insert for b[j], so we need k >= b[j]
            answer = min(answer, b[j]);
        }
    }

    if (answer == LLONG_MAX) cout << -1 << "\n";
    else                 cout << answer << "\n";
}


/*
NOTES:
   1 3 2 5 4

5= 4 2 3 0 1
6= 
7=
8= 
9= 
10=


*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}