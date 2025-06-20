/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// C. Gellyfish and Flaming Peony
// URL: https://codeforces.com/contest/2116/problem/C
// Time: 5/31/2025, 8:53:54 PM
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

int dp[5001][5001];

void Ramez() {
    int n; cin >> n;
    vi a(n); cin >> a;

    int minA = *min_element(all(a));

    int g = a[0];
    for (int i = 1; i < n; i++){
        g = gcd(g, a[i]);
    }
    
    int cntG = 0;

    for (int i = 0; i < n; i++){
        if(a[i] == g) cntG++;
    }

    if(cntG > 0) {
        cout << n - cntG << "\n";
        return;
    }


    for (int x = 1; x <= 5000; x++) {
        dp[0][x] = INT_MAX;
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= 5000; j++){
            dp[i][j] = dp[i - 1][j]; // -> not taking
        }  

        for (int j = 1; j <= 5000; j++){
            if(dp[i - 1][j] == INT_MAX) continue;
            int newGCD = gcd(j, a[i - 1]);
            dp[i][newGCD] = min(dp[i][newGCD], dp[i - 1][j] + 1); // -> taking
        }

        dp[i][a[i - 1]] = min(dp[i][a[i - 1]], 1LL); // -> start new        
    }
    
    int answer = (n - 1) + (dp[n][g] - 1);
    cout << answer << "\n";
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