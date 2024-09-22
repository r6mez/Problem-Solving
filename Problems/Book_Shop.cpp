// Ramez Medhat
// problem: Book Shop
// URL: https://cses.fi/problemset/task/1158  
// Start: 7/10/2024, 11:18:51 PM
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <numeric>
using namespace std;
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vll vector<long long>
#define all(v)  v.begin(), v.end()
const int MOD = 1000000007;
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for (const auto& i : v) os << i << ' ';
    return os;
}
template<typename T>
istream& operator>>(istream& is, vector<T>& v) {
    for (auto& i : v) is >> i;
    return is;
}



void solve() {
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> pricePages(n);
    for (int i = 0; i < n; i++) {
        cin >> pricePages[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> pricePages[i].second;
    }

    vector<vi> dp(n + 1, vi(x + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            if (j - pricePages[i - 1].first >= 0) dp[i][j] = max(dp[i-1][j], pricePages[i - 1].second + dp[i - 1][j - pricePages[i - 1].first]);
            else dp[i][j] = dp[i - 1][j];
        }
    }

    cout << dp[n][x];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}