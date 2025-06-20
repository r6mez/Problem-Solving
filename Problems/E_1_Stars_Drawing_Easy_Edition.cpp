/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// E1. Stars Drawing (Easy Edition)
// URL: https://codeforces.com/problemset/problem/1015/E1
// Time: 6/16/2025, 9:50:25 PM
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
    vector<string> a(n); cin >> a;

    vector<vi> stars;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '*') {
                int k = 1;
                while (i - k >= 0 && i + k < n && j - k >= 0 && j + k < m &&
                    a[i - k][j] == '*' && a[i + k][j] == '*' &&
                    a[i][j - k] == '*' && a[i][j + k] == '*') {
                    k++;
                }
                k--; 
                if (k > 0) stars.push_back({ i + 1, j + 1, k });
            }
        }
    }


    vector<vector<bool>> covered(n, vector<bool>(m, false));

    for (vi star : stars) {
        int i = star[0] - 1, j = star[1] - 1, s = star[2];
        covered[i][j] = true;
        for (int k = 1; k <= s; ++k) {
            covered[i + k][j] = true;
            covered[i - k][j] = true;
            covered[i][j + k] = true;
            covered[i][j - k] = true;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '*' && covered[i][j] == false) {
                cout << "-1";
                return;
            }
        }

    }


    cout << stars.size() << "\n";
    for (vi p : stars) {
        cout << p << "\n";
    }
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