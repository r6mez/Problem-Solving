/*
    One day, I'm gonna grow wings
*/
// C2. The Cunning Seller (hard version)
// URL: https://codeforces.com/contest/2132/problem/C2
// Time: 8/21/2025, 6:19:59 PM
#include <bits/stdc++.h>
using namespace std;
#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> auto& operator<<(auto& o, vector<T>& v) { for (auto& e : v) o << e << ' '; return o; }
template<typename T> auto& operator>>(auto& i, vector<T>& v) { for (auto& e : v) i >> e; return i; }
void FastIO() { cin.tie(nullptr)->sync_with_stdio(false); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007;

void solve() {
    int n, k; cin >> n >> k;

    int cost = 0, minDeals = 0;

    map<int, int> deals;
    int x = 0, p = 1;

    while (n > 0) {
        int d = n % 3;
        cost += d * (p * 3 + x * (p / 3));
        deals[x] = d;
        minDeals += d;
        n /= 3;
        p *= 3;
        x++;
    }

    if (k < minDeals) {
        cout << "-1\n";
        return;
    }

    p /= 3;
    x--;

    for (int i = x; i >= 1; i--) {
        int newDeals = min(deals[i], (k - minDeals) / 2);
        if (deals[i] && newDeals) {
            minDeals += newDeals * 2;
            deals[i] -= newDeals;
            deals[i - 1] += newDeals * 3;
            cost -= newDeals * (p / 3);
        }
        p /= 3;
    }

    cout << cost << "\n";
}

/*

*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}