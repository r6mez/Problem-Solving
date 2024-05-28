// ﷽
// problem: B. Binary Colouring
// URL: https://codeforces.com/contest/1977/problem/B  
// Start: 5/26/2024, 5:38:25 PM
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
   ll x;
    cin >> x;
    vector<int> res(31, 0);
    for (int i = 0; i < 30; i++) {
        if (1ll & (x >> i)) {
            if (res[i]) {
                res[i + 1] = 1;
                res[i] = 0;
            } else if (i > 0) {
                if (res[i - 1] == 1) {
                    res[i + 1] = 1;
                    res[i - 1] = -1;
                } else {
                    res[i] = 1;
                }
            } else if (i == 0) {
                res[i] = 1;
            }
        }
    }
    cout << 31 << '\n';
    for (int i = 0; i <= 30; i++) {
        cout << res[i] << ' ';
    }
    cout << '\n';
}

/*
NOTES:
0101 = 5
1001 = 9
1101 = 13
1110 = 14


We need to construct an array, its elements either 0, 1 , -1,
the array has no values beside each other that is one of them not equal to 0,
and the sum of the array after multiplying each element by 2^i = x

14 / 2 = 7 -- 0 1110
7  / 2 = 3 -- 1 0111
3  / 2 = 1 -- 1 0011
1  / 2 = 0 -- 1 0001

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