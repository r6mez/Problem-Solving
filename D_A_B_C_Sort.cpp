// ﷽
// problem: D. A-B-C Sort
// URL: https://codeforces.com/problemset/problem/1674/D  
// Start: 6/7/2024, 12:27:08 PM
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

    vi a(n); cin >> a;

    for (int i = 0; i < n - 1; ++i) {
        if (((n - i) % 2) == 0 && a[i] >  a[i + 1])
            swap(a[i], a[i + 1]);
    }

    // check if sorted
    for (int i = 0; i + 1 < n; ++i) {
        if (a[i + 1] < a[i]) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

/*
NOTES:
a 3 2 1
b 2 3 1
c 1 2 3
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