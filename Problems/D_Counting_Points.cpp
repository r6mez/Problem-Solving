/*
I thought I could bring an end to the world suffering,
But when every equation was solved
all that remained were fields of dreamless solitude.
*/
// D. Counting Points
// URL: https://codeforces.com/contest/2074/problem/D
// Time: 3/11/2025, 5:37:14 PM
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
    int n, m; cin >> n >> m;
    vi x(n), r(n); cin >> x >> r;

    map<int, int> mp;

    for (int i = 0; i < n; i++) {
        for (int x2 = x[i] - r[i]; x2 <= x[i] + r[i]; x2++) {
            int y = sqrt(pow(r[i] - 0, 2) - pow(x2 - x[i], 2));
            mp[x2] = max(mp[x2], y);
        }
    }

    int counter = 0;
    for (auto& [x, y] : mp) {
        counter += y * 2 + 1;
    }

    cout << counter << "\n";
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