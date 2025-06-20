/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// G. 2^Sort
// URL: https://codeforces.com/problemset/problem/1692/G
// Time: 6/6/2025, 6:29:34 PM
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
    vi a(n); cin >> a;
    vi b(n); 
    for (int i = 0; i < n - 1; i++){
        b[i] = (a[i] < 2*a[i + 1]);
    }

    b[n - 1] = 1;

    partial_sum(all(b), b.begin());

    int cnt = 0;
    for (int i = 0; i < n - k; i++){
        int sum = b[i + k - 1] - (i ? b[i - 1] : 0);
        cnt += (sum == k );
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
    cin >> t;
    while (t--) Ramez();
    return 0;
}