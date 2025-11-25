/*
    One day, I'm gonna grow wings
*/
// A. Mr. Kitayuta, the Treasure Hunter
// URL: https://codeforces.com/problemset/problem/506/A
// Time: 11/2/2025, 5:32:59 PM
#include <bits/stdc++.h>
using namespace std;
#define int         long long
#define vi          vector<int>
#define pii         pair<int, int>
#define all(v)      v.begin(), v.end()
#define finish(s)   { cout << s << "\n"; return; }
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { cin.tie(nullptr)->sync_with_stdio(false); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007, INF = 2e18;

const int MAXP = 30000;
int freqArr[MAXP+1];

void solve() {
    memset(freqArr,0,sizeof(freqArr));
    int n,d0; cin>>n>>d0;
    vi a(n); for(int i=0;i<n;i++) cin>>a[i];
    for(int v: a) if(v<=MAXP) freqArr[v]++;

    int K = (int)floor(sqrt(2.0*MAXP))+2;
    int baseD = max(1LL, d0 - K);
    int maxD = min((long long)MAXP, d0 + K);
    int width = (int)(maxD - baseD + 1);

    vector<vector<int>> dp(MAXP+1, vector<int>(width, 0));

    for(int x = MAXP; x >= 0; --x){
        for(int j = 0; j < width; ++j){
            int d = baseD + j;
            int best = 0;
            int nx;
            nx = x + d - 1;
            if(d - 1 >= baseD && nx <= MAXP) best = max(best, dp[nx][(d-1)-baseD]);
            nx = x + d;
            if(nx <= MAXP) best = max(best, dp[nx][d-baseD]);
            nx = x + d + 1;
            if(d + 1 <= maxD && nx <= MAXP) best = max(best, dp[nx][(d+1)-baseD]);
            dp[x][j] = freqArr[x] + best;
        }
    }

    cout << dp[d0][d0 - baseD] << '\n';
}

/*

*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) solve();
}