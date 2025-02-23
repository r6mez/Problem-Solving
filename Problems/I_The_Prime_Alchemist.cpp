/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all that remained were fields of dreamless solitude.
*/
// I. The Prime Alchemist
// URL: https://codeforces.com/group/6aLUitEJUs/contest/590165/problem/I
// Time: 2/21/2025, 9:59:07 PM
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

int next(int x, int t) {
    if (x < t) return -1;

    if (x == 1 || x == 2) {
        return (t == x ? x : -1);
    }
    
    if (t <= x - 2)
        return t;

    if (t == x - 1)
        return x;

    if (t == x)
        return x;

    return -1;
}

void Ramez() {
    int n; cin >> n;
    vector<int> v(n); cin >> v;

    if (v[0] != 2) v[0] = 1;
    
    for (int i = 1; i < n; i++) {
        v[i] = next(v[i], v[i - 1] + 1);
    }
    
    for (int i = 1; i < n; i++) {
        if (v[i] <= v[i - 1]) {
            cout << "NO\n";
            return;
        }
    }
    
    cout << "YES\n";
}

/*
NOTES:
5
-2 -> 3
-3 -> 2

8 6 4 2 0
8 5 3 1
8 6 4 1
8 6 3 1
8 6 4 1

9 7 5 3 1
9 6 4 2 0

if the number is even
it can be any even number <= it
it can be any odd number <= it except a[i] - 1
*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}

