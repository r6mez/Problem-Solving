/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all that remained were fields of dreamless solitude.
*/
// F - Sambosa/Sambosak
// URL: https://vjudge.net/contest/695647#problem/F
// Time: 2/21/2025, 8:09:28 PM
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

vector<vi> prefixSum2D(vector<vi>& a) {
    vector<vi> b(a.size(), vi(a[0].size()));
    for (int i = 0; i < a.size(); i++) {
        partial_sum(all(a[i]), b[i].begin());
    }
    for (int i = 0; i < a[0].size(); i++) {
        for (int j = 1; j < a.size(); j++) {
            b[j][i] += b[j - 1][i];
        }
    }
    return b;
}

int sumOfSquare(int x1, int y1, int x2, int y2, vector<vi>& a) {
    int res = a[x2][y2];
    if (x1 > 0) res -= a[x1 - 1][y2];
    if (y1 > 0) res -= a[x2][y1 - 1];
    if (x1 > 0 && y1 > 0) res += a[x1 - 1][y1 - 1];
    return res;
}
// asdasd
void Ramez() {
    int n, m, a, b; cin >> n >> m >> a >> b;
    string s; cin >> s;
    vector<vector<char>> fridge(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> fridge[i][j];
        }
    }

    vi freq(26);

    for (int i = 0; i < s.size(); i++) {
        freq[s[i] - 'a']++;
    }


    vector<vector<vector<int>>> prefixBox(26, vector<vector<int>>(n, vector<int>(m, 0)));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            prefixBox[fridge[i][j] - 'a'][i][j]++;
        }
    }

    for (int i = 0; i < 26; i++) {
        prefixBox[i] = prefixSum2D(prefixBox[i]);
    }

    int maxMade = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i + a - 1 < n && j + b - 1 < m) {
                int made = INT_MAX;

                for (int k = 0; k < 26; k++) {
                    if (freq[k] == 0) continue;
                    int sum = sumOfSquare(i, j, i + a - 1, j + b - 1, prefixBox[k]);
                    made = min(made, sum / freq[k]);
                    if (made == 0) break;
                }

                maxMade = max(maxMade, made);
            }

            if (i + b - 1 < n && j + a - 1 < m) {
                int made = INT_MAX;

                for (int k = 0; k < 26; k++) {
                    if (freq[k] == 0) continue;
                    int sum = sumOfSquare(i, j, i + b - 1, j + a - 1, prefixBox[k]);
                    made = min(made, sum / freq[k]);
                    if (made == 0) break;
                }

                maxMade = max(maxMade, made);
            }
        }
    }

    cout << maxMade << "\n";
}

/*
NOTES:

*/

int32_t main() {
    // UseFile();
    // FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}

