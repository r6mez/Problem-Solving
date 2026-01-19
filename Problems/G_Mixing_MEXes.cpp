// G. Mixing MEXes
// URL: https://codeforces.com/contest/2185/problem/G
// Time: 1/19/2026, 2:28:45 PM
#include <bits/stdc++.h>
using namespace std;
#define int         long long
#define vi          vector<int>
#define pii         pair<int, int>
#define all(v)      v.begin(), v.end()
#define finish(s)   { cout << s << "\n"; return; }
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { cin.tie(nullptr)->sync_with_stdio(false); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007, INF = 2e18;

void solve() {
    
}

/*
n array
sum of all mexes of the arrays for all possible moves
a move: choose an array i and element j and move it to array k (i != k)

number of all elements <= 1e5

for each element in array, you need to try to move it to every other array
if we moved x to array with mex y
    if (x == y) mex changes (next missing number)
    other wise mex stays the same
if the original array has another x or mex < x, mex stays the same



*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) solve();
}