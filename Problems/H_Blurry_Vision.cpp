/*
    I thought I could bring an end to the world's suffering,
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// H. Blurry Vision
// URL: https://codeforces.com/contest/2095/problem/H
// Time: 4/1/2025, 5:11:14 PM
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
    string s[11] = {
        "CODEFORCES",
        "EYE",
        "TESTING",
        "SYSTEM",
        "APRIL",
        "FOOLS",
        "IS", // DAY, 2025, CONTEST, EYE, THE, IS
        "",
        "",
        "",
        "",
    };

    int n; cin >> n;
    cout << s[n - 1] << "\n";
}

/*
NOTES:

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}