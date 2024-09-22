// ﷽
// problem: C. Beautiful Triple Pairs
// URL: https://codeforces.com/contest/1974/problem/C  
// Start: 5/20/2024, 6:06:13 PM
#include <bits\stdc++.h>
#include <array>
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
    int n;
    cin >> n;
    vi a(n); cin >> a;

    map<array<int, 3>, map<int, int>> m;
    for (int i = 0; i + 3 <= n; i++) {
        m[{0, a[i + 1], a[i + 2]}][a[i]]++;
        m[{a[i], 0, a[i + 2]}][a[i + 1]]++;
        m[{a[i], a[i + 1], 0}][a[i + 2]]++;
    }

    ll sol = 0;
    for (auto& [triple, mp] : m) {
        ll sum = 0;
        for (auto& [k, freq] : mp) {
            sol += sum * freq;
            sum += freq;
        }
    }

    cout << sol << '\n';
}

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