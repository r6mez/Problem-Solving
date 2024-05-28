// ﷽
// problem: A. AvtoBus
// URL: https://codeforces.com/problemset/problem/1679/A  
// Start: 5/28/2024, 11:28:21 PM
#include <bits\stdc++.h>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;
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
    ll n; cin >> n;

    if (n % 2 == 0 && n >= 4) {
        cout << (n+4) / 6 << ' ' << n / 4 << '\n';
    }
    else {
        cout << -1 << '\n';
    }
}

/*
NOTES:
6 6 6 6 6 6 + 2 = x/6
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