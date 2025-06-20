/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// C. Smilo and Minecraft
// URL: https://codeforces.com/contest/2113/problem/C
// Time: 6/15/2025, 6:20:21 PM
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

 int n, m, k;

vector<vi> prefixSum2D(vector<vi>& a) {
    vector<vi> b(a.size(), vi(a[0].size()));
    for (int i = 0; i < a.size(); i++) {
        partial_sum(all(a[i]), b[i].begin());
    }
    for (int i = 0; i < a[0].size(); i++) {
        for (int j = 1; j < a.size(); j++) {
            b[j][i] += b[j - 1][i];
        }
    }
    return b;
}

int sumOfSquare(int x1, int y1, int x2, int y2, vector<vi>& a) {
    x1 = max(x1, 1LL);
    y1 = max(y1, 1LL);
    x2 = min(x2, (int)a.size() - 1);
    y2 = min(y2, (int)a[0].size() - 1);
    return (a[x2][y2] - a[x1 - 1][y2] - a[x2][y1 - 1]) + a[x1 - 1][y1 - 1];
}

void Ramez() {
    int n, m, k; cin >> n >> m >> k;
    vector<string> cave(n); cin >> cave;

    vector<vi> pre(n + 1, vi(m + 1));

    int gold = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (cave[i - 1][j - 1] == 'g') pre[i][j] = 1, gold++;
        }
    }

    pre = prefixSum2D(pre);

    int minLoss = INT_MAX;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (cave[i - 1][j - 1] == '.') {
                int loss = sumOfSquare(i - k + 1, j - k + 1, i + k - 1, j + k - 1, pre);
                minLoss = min(minLoss, loss);
            }
        }
    }

    if (minLoss != INT_MAX) cout << gold - minLoss << "\n";
    else cout << 0 << "\n";
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