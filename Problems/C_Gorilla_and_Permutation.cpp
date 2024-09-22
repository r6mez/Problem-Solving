// Ramez Medhat
// problem: C. Gorilla and Permutation
// URL: https://codeforces.com/contest/1992/problem/C  
// Start: 7/11/2024, 5:52:23 PM
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
#include <numeric>
using namespace std;
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vll vector<long long>
#define all(v)  v.begin(), v.end()
const int MOD = 1000000007;
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
    int n, m, k;
    cin >> n >> m >> k;

    vi perm(n);

    for (int i = 0; i < n; i++) {
        perm[i] = i+1;       
    }

    reverse(perm.begin(), perm.begin()+m);

    reverse(all(perm));

    cout << perm << "\n";
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