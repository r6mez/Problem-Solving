#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll maxSum(vector<vector<ll>>& a, int i = 0, int j = 0, ll sum = 0) {
    if (i == a.size() - 1 && j == a[0].size() - 1) {
        return sum + a[i][j];
    }
    ll right = LLONG_MIN, down = LLONG_MIN;
    if (j < a[0].size() - 1) {
        right = maxSum(a, i, j + 1, sum + a[i][j]);
    }
    if (i < a.size() - 1) {
        down = maxSum(a, i + 1, j, sum + a[i][j]);
    }
    return max(right, down);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    cout << maxSum(a) << "\n";
    return 0;
}
