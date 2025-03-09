/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all that remained were fields of dreamless solitude.
*/
// K. Sagheer and Nubian Market
// URL: https://codeforces.com/group/3nQaj5GMG5/contest/376466/problem/K
// Time: 3/9/2025, 4:44:52 PM
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

int getTotalCost(int k, int S, vi &baseCosts) {
    vi totalCosts;
    for (int i = 0; i < baseCosts.size(); ++i) {
        totalCosts.push_back(baseCosts[i] + (long long)(i + 1) * k);
    }
 
    sort(totalCosts.begin(), totalCosts.end());
    int sum = 0;
 
    for (int i = 0; i < k; ++i) {
        sum += totalCosts[i];
    }
 
    return sum;
}
 

void Ramez() {
    int n, s; cin >> n >> s;
    vi baseCosts(n); for (int& i : baseCosts) cin >> i;


    int left = 0, right = n+1, maxK = 0;
    int minTotalCost = LLONG_MAX;
    while (left + 1 < right) {
        int mid = left + (right - left) / 2;
        int totalCost = getTotalCost(mid, s, baseCosts);
        if (totalCost <= s) {
            maxK = mid;
            minTotalCost = min(minTotalCost, totalCost);
            left = mid;
        }
        else {
            right = mid;
        }
    }

    minTotalCost = getTotalCost(maxK, s, baseCosts);

    cout << maxK << " " << minTotalCost;
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