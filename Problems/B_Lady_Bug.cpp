/*
    I thought I could bring an end to the world's suffering,
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// B. Lady Bug
// URL: https://codeforces.com/problemset/problem/2092/B
// Time: 4/26/2025, 11:09:14 PM
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
    int n; cin >> n;
    string a, b; cin >> a >> b;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; ++i) {
        if (i & 1) {
            cnt2 += a[i] == '0';
            cnt1 += b[i] == '0';
        } else {
            cnt1 += a[i] == '0';
            cnt2 += b[i] == '0';
        }
    }
    cout << (cnt1 >= (n + 1) / 2 && cnt2 >= n / 2 ? "Yes" : "No") << '\n';
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