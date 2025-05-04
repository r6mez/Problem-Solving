#include <iostream>
#include <vector>
using namespace std;

int maxSubsetSumDP(const vector<int>& v, int k) {
    vector<bool> dp(k + 1, false);
    dp[0] = true;

    for (int x : v) {
        for (int s = k; s >= x; --s) {
            if (dp[s - x]) dp[s] = true;
        }
    }

    for (int s = k; s >= 0; --s) {
        if (dp[s]) return s;
    }
    return 0;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    cout << maxSubsetSumDP(v, k) << "\n";
    return 0;
}
