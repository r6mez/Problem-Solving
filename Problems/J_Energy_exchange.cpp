/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all that remained were fields of dreamless solitude.
*/
// J. Energy exchange
// URL: https://codeforces.com/group/3nQaj5GMG5/contest/376466/problem/J
// Time: 3/9/2025, 4:19:39 PM
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
    double n, k; cin >> n >> k;
    vi a(n); cin >> a;
    double sum = accumulate(all(a), 0.0);

    double l = 0, r = sum / n;

    while (l + 1e-8 < r) {
        double mid = (l + r) / 2;

        double lossFactor = 1 - k / 100.0;
        double surplus = 0.0, deficit = 0.0;

        for (double energy : a) {
            if (energy > mid) surplus += (energy - mid) * lossFactor;
            else deficit += (mid - energy);
        }

        bool can = surplus >= deficit;
        if (can) l = mid;
        else r = mid;
    }

    cout << fixed << setprecision(9) << l;
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