/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// C2. Potions (Hard Version)
// URL: https://codeforces.com/contest/1526/problem/C2
// Time: 6/14/2025, 7:43:19 PM
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

namespace std {
    template<>
    struct hash<pii> {
        size_t operator()(const pii& p) const {
            return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
        }
    };
}

void Ramez() {
    int n; cin >> n;
    vi a(n); cin >> a;

    priority_queue<int, vector<int>, greater<int>> pq; 
    int sum = 0;
    int cnt = 0;

    for (int i = 0; i < n; ++i) {
        sum += a[i];
        pq.push(a[i]);
        cnt++;

        if (sum < 0) {
            int mn = pq.top(); pq.pop();
            sum -= mn; 
            cnt--; 
        }
    }

    cout << cnt << endl;
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