/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// C2. k-LCM (hard version)
// URL: https://codeforces.com/problemset/problem/1497/C2
// Time: 6/9/2025, 7:56:51 PM
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

vi dude(int n) {
    if (n % 2 == 1) return {1, n / 2, n / 2};
    if (n % 4 == 0) return {n / 2, n / 4, n / 4};
    if (n % 2 == 0) return {2, n / 2 - 1, n / 2 - 1};
}

void Ramez() {
    int n, k; cin >> n >> k;
    vi d = dude(n - k + 3);
    cout << d;
    for (int i = 0; i < k - 3; i++){
        cout << 1 << " ";
    }
    cout << "\n";
}

/*
NOTES:
15 7
5 5 1 1 1 1 1
*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}