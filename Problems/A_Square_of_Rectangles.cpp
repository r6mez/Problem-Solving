/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// A. Square of Rectangles
// URL: https://codeforces.com/contest/2120/problem/0
// Time: 6/21/2025, 5:36:52 PM
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
    vi w(3), l(3); cin >> w[0] >> l[0] >> w[1] >> l[1] >> w[2] >> l[2];

    int sumW = w[0] + w[1] + w[2];

    if (sumW == l[0] && sumW == l[1] && sumW == l[2]) {
        cout << "YES\n";
        return;
    }

    int sumL = l[0] + l[1] + l[2];

    if (sumL == w[0] && sumL == w[1] && sumL == w[2]) {
        cout << "YES\n";
        return;
    }


    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (i == j || j == k || i == k) continue;
                if (w[i] == w[j] + w[k] && w[i] == l[i] + l[j] && l[j] == l[k]) {
                    cout << "YES\n";
                    return;
                }

                if (l[i] == l[j] + l[k] && l[i] == w[i] + w[j] && w[j] == w[k]) {
                    cout << "YES\n";
                    return;
                }
            }
        }
    }

    cout << "NO\n";
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