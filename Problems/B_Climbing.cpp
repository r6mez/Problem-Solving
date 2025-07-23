/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// B. Climbing
// URL: https://codeforces.com/group/Rilx5irOux/contest/603455/problem/B
// Time: 7/8/2025, 2:23:35 PM
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
    int n, j, h; cin >> n >> j >> h;
    vi a(n); cin >> a;

    auto can = [&](int k) -> bool {
        if (k == 0) {
            return true; 
        }

        vi costs;
        costs.push_back(a[0]); 
        for (int i = 0; i < k - 1; ++i) {
            if (a[i + 1] > a[i]) {
                costs.push_back(a[i + 1] - a[i]);
            }
        }
        
        sort(costs.rbegin(), costs.rend());

        int neededH = 0;
        for (int i = j; i < costs.size(); ++i) {
            neededH += costs[i];
        }
        return neededH <= h;
    };

    int l = 0, r = n + 1;
    while (l + 1 < r) {
        int mid = l + (r - l) / 2;
        if (can(mid)) l = mid;
        else r = mid;
    }
    cout << l << endl;
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