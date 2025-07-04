/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// F. Minimize Fixed Points
// URL: https://codeforces.com/contest/2123/problem/F
// Time: 7/1/2025, 7:07:56 PM
#include <bits/stdc++.h>
using namespace std;
#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007;

int biggestDivisor(int a) {
    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0) return a / i;
    }
    return a;
}

void Ramez() {
    int n; cin >> n;
    vi p(n + 1); iota(all(p), 0);
    for (int i = 4; i <= n; i++) swap(p[i], p[biggestDivisor(i)]);
    for (int i = 1; i <= n; i++) cout << p[i] << " "; cout << "\n";
}

/*
NOTES:
1 12 9 6 10 8 7 4 3 5  11 2  13
1 2  3 4 5  6 7 8 9 10 11 12 13
1             7        11    13
2 12
3 9
4 6 8

1
2 4 6 8 10 12
3 6 9
4 8 12
5 10
6 12
7
8
9
10
11
12
13
*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}