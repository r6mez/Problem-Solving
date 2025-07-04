/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// C. Lucky Numbers
// URL: https://codeforces.com/contest/630/problem/C
// Time: 6/26/2025, 3:59:33 PM
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

int pw(int a, int b) {
    int result = 1;
    while (b > 0) {
        if (b & 1) result = result * a;
        a = a * a;
        b /= 2;
    }
    return result;
}

void Ramez() {
    int n; cin >> n;
    int cnt = 0;
    for (int i = 1; i <= n; i++){
        cnt += pw(2LL, i);
    }
    cout << cnt << "\n";
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