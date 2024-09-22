// ﷽
// problem: C1. Magnitude (Easy Version)
// URL: https://codeforces.com/contest/1984/problem/C1  
// Start: 6/9/2024, 6:18:52 PM
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
#include <unordered_map>
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
    vi a(n);
    cin >> a;

    ll curr = 0, min_pre = 0, max_ans = 0;
    for (int i : a) {
        curr += i;
        min_pre = min(min_pre, curr);
    }

    ll x = curr - (min_pre << 1);
    max_ans = max(curr, x);

    cout << max_ans << '\n';
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


/*
NOTES:
10 -9 -3 4
10 - 9 = 1
1 - 3 = -2 == 2
2 + 4 = 6

-1000000000 1000000000 1000000000 1000000000
0 + 1000000000 =

-1 -2 3 4 5
1 + 2 = 3
3 - 3 = 0
0 + 7 = 7
7 +

0 + -3 = 3
3 + 2 = 5
5 - 3 = 2
2 + 7 = 9
9 - 5 = 4

-3 + 0 = -3
-3 + 2 = 1
1 - 3 = 2
2 + 7 = 9
9 - 5 = 4

-3 + 0 = -3
-3 + 2 = -1
-1 - 3 = 4
4 + 7 = 11
11 - 5 = 6

5
-3 2 -3 7 -5

-3 + 2 - 3 = 4
4 + 7 = 11
11 - 5 = 6


7
-1 -10 -10 -10 4 -5 3

-1 -10 -10 -10 + 4 -5 = 32
32 + 3 = 35

*/
