// ﷽
// problem: B. Same Parity Summands
// URL: https://codeforces.com/problemset/problem/1352/B  
// Start: 6/6/2024, 6:40:29 PM
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
    int n, k;
    cin >> n >> k;
    int n1 = n - (k - 1);
    if (n1 > 0 && n1 % 2 == 1) {
        cout << "YES" << endl;
        for (int i = 0; i < k - 1; ++i) cout << "1 ";
        cout << n1 << endl;
        return;
    }
    int n2 = n - 2 * (k - 1);
    if (n2 > 0 && n2 % 2 == 0) {
        cout << "YES" << endl;
        for (int i = 0; i < k - 1; ++i) cout << "2 ";
        cout << n2 << endl;
        return;
    }
    cout << "NO" << endl;
}

/*
NOTES:
10 3
4 4 2
if(n%k == 0 || n%k+x)
    x x x x
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