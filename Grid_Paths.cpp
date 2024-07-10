// Ramez Medhat
// problem: Grid Paths
// URL: https://cses.fi/problemset/task/1638  
// Start: 7/10/2024, 9:44:51 PM
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
#define search(vec, item) find(all(vec), item) != vec.end()
vector<vi> repGraph(int n, int m);
void dfs(int parent, vector<vi>& graph, vector<bool>& visited);
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

const int MOD = 1000000007;

void solve() {
    int n; cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    int validPaths = 0;

    vector<vector<int>> dp(n, vector<int>(n, 0));
    if (grid[0][0] != '*') {
        dp[0][0] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '*') {
                dp[i][j] = 0;
            }
            else {
                if (i > 0) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
                }
                if (j > 0) {
                    dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
                }
            }
        }
    }

    cout << dp[n-1][n-1] << "\n";
}

/*
NOTES:

*/

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