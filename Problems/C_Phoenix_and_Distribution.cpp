/*
    I thought I could bring an end to the world's suffering,
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// C. Phoenix and Distribution
// URL: https://codeforces.com/problemset/problem/1348/C
// Time: 4/15/2025, 6:21:55 PM
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

void Ramez() {
    int n, k; cin >> n >> k;
    string s; cin >> s;

    sort(all(s));

    if (s[0] != s[k - 1]) {
        cout << s[k - 1] << "\n";
    }
    else {
        cout << s[0];
        if (s[k] != s[n - 1]) {
            cout << s.substr(k, n) << "\n";
        } else {
            cout << string((n - 1) / k, s[n - 1]) << "\n";
        }
    }
}

/*
NOTES:
k = 2
a b c
2 3 4

aabbbcccc
k = 2
abbcccc
ab

k = 3
abcc
abcc
b

k = 4
abc
abc
bc
c


baacb
k = 2
a
abbc

we will try to construct a k - 1 string with letter from a to z
in an increasing order

then the rest of the letter are the answer

baacb
k = 3
a
abc
b
*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}