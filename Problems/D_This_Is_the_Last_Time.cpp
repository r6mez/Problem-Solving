/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// D. This Is the Last Time
// URL: https://codeforces.com/contest/2126/problem/D
// Time: 7/17/2025, 6:01:15 PM
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
    vector<array<int, 3>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }

    sort(all(a));

    int pos = k, i = 0;
    priority_queue<pii> pq;
    while (true) {
        while (i < n && a[i][0] <= pos) pq.emplace(a[i][2], a[i][1]), i++;

        bool ok = false;
        while (!pq.empty()) {
            auto [real, r] = pq.top(); pq.pop();
            if (pos > r) continue;    
            if (real > pos) pos = real, ok = true;
            break;
        }

        if (!ok) break;
    }

    cout << pos << "\n";
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