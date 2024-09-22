// ﷽
// problem: B. Maximum Multiple Sum
// URL: https://codeforces.com/contest/1985/problem/B  
// Start: 6/11/2024, 5:37:14 PM
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
using namespace std;
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vll vector<long long>
#define all(v)  v.begin(), v.end()

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
    int n; cin >> n;
    int sum = 0, res = 2;

    for (int x = 2; x <= n; ++x) {
        int k = n / x, currSum = x * k * (k + 1) / 2;
        if (currSum > sum) {
            res = x;
            sum = currSum;
        }
    }

    cout << res << "\n";
}

/*
NOTES:

*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}