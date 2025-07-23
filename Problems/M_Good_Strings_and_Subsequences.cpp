/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// M. Good Strings and Subsequences
// URL: https://codeforces.com/group/Rilx5irOux/contest/620530/problem/M
// Time: 7/18/2025, 6:34:42 PM
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

int add(int a, int b){ 
    a += b; 
    if(a >= MOD) a -= MOD;
    return a;
}

void Ramez() {
    int n, m;
    string t;
    cin >> n >> m >> t;

    // Precompute vowel‐set lookup
    static bool isV[26] = {};
    for (char c : string{ "aeiou" }) isV[c - 'a'] = true;

    // Maximum vowels you ever need to track:
    // solve v^2 + v ≤ n  ⇒  v ≤ floor((√(1+4n)-1)/2)
    int Vmax = (sqrt(1.0 + 4.0 * n) - 1.0) / 2.0;

    // dp[2][j=0..m][v=0..Vmax][lastV=0/1]
    static int dp[2][501][501][2];
    dp[0][0][0][0] = 1;

    for (int i = 0; i < n; i++) {
        int cur = i & 1;
        int nxt = cur ^ 1;
        memset(dp[nxt], 0, sizeof dp[nxt]);

        for (int j = 0; j <= m; j++) {
            for (int v = 0; v <= Vmax; v++) {
                for (int lastV = 0; lastV < 2; lastV++) {
                    int ways = dp[cur][j][v][lastV];
                    if (!ways) continue;

                    // 1) append a consonant (21 choices total)
                    //    gamma = 1 if t[j] is a consonant (and j<m), else 0
                    int gamma = (j < m && !isV[t[j] - 'a']) ? 1 : 0;
                    // matching consonant(s) that advance j:
                    dp[nxt][j + gamma][v][0] = add(
                        dp[nxt][j + gamma][v][0],
                        1LL * ways * gamma % MOD
                    );
                    // the rest:
                    dp[nxt][j][v][0] = add(
                        dp[nxt][j][v][0],
                        1LL * ways * (21 - gamma) % MOD
                    );

                    // 2) append a vowel (5 choices), only if last wasn't a vowel
                    if (lastV == 0 && v + 1 <= Vmax) {
                        // delta = 1 if t[j] is a vowel (and j<m), else 0
                        int delta = (j < m && isV[t[j] - 'a']) ? 1 : 0;
                        dp[nxt][j + delta][v + 1][1] = add(
                            dp[nxt][j + delta][v + 1][1],
                            1LL * ways * delta % MOD
                        );
                        dp[nxt][j][v + 1][1] = add(
                            dp[nxt][j][v + 1][1],
                            1LL * ways * (5 - delta) % MOD
                        );
                    }
                }
            }
        }
    }

    // Sum up only those end‐states where we’ve matched the entire t (j=m)
    // and the final (V,C) obey V^2 ≤ C  ⇒  V^2 ≤ (n - V)
    int ans = 0, last = n & 1;
    for (int v = 0; v <= Vmax; v++) {
        if (1LL * v * v <= n - v) {
            ans = add(ans, dp[last][m][v][0]);
            ans = add(ans, dp[last][m][v][1]);
        }
    }

    cout << ans << "\n";
}

/*
NOTES:

t -> (x vowels, y consenets)
number of way to distrubute
stars and bars m letter from n from
if there's vowels
26 ^ m


*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}