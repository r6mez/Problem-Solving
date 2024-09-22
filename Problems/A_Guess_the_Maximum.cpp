// ﷽
// problem: A. Guess the Maximum
// URL: https://codeforces.com/contest/1979/problem/A  
// Start: 6/6/2024, 10:27:51 PM
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
    int n;
    cin >> n;
    vi a(n); cin >> a;
    int mini = max(a[0], a[1]);
    for (int i = 1; i < n - 1; i++) {
        mini = min(mini, max(a[i], a[i + 1]));
    }
    cout << mini - 1 << "\n";
}

/*
NOTES:
alice chooses k
bob chooses i, j
if max(ai:aj) > k alice wins
else bob lose
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