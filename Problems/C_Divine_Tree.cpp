/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// C. Divine Tree
// URL: https://codeforces.com/contest/2120/problem/C
// Time: 6/21/2025, 6:16:19 PM
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
    int n, m; cin >> n >> m;

    if (m < n || m > n * (n + 1) / 2) {
        cout << -1 << endl;
        return;
    }

    int root = 0;
    for (int i = 1; i <= n; ++i) {
        int leaves = n - i;
        if (m <= i * (i + 1) / 2 + leaves * i) {
            root = i;
            break;
        }
    }

    cout << root << "\n";

    for (int i = root; i >= 2; i--) {
        cout << i - 1 << " " << i << "\n";
    }

    int cnt = n - root;
    if (cnt > 0) {
        int sum = m - root * (root + 1) / 2;
        int q = sum / cnt, curr = root + 1;

        for (int i = 0; i < cnt; ++i) {
            cout << q + (i < sum % cnt) << " " << curr << "\n";
            curr++;
        }
    }
}


/*
NOTES:
n

n * (n - 1)
*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}