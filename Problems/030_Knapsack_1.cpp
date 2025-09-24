/*
    One day, I'm gonna grow wings
*/
// 030 - Knapsack 1
// URL: https://atcoder.jp/contests/math-and-algorithm/tasks/dp_d?lang=en
// Time: 9/10/2025, 9:51:02 PM
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
const int MOD = 1000000007;

struct Items {
    int w, v;
};

const int N = 100 + 1, W = 1e5 + 1, INF = 2e18;
int dp[N][W];
int n, w;
vector<Items> a;

int calcRecursive(int i, int currW){
    if(currW > w) return -INF;
    if(i == n) return 0;

    int &p = dp[i][currW];
    if(p != -1) return p;

    int take = calcRecursive(i + 1, currW + a[i].w) + a[i].v;
    int leave = calcRecursive(i + 1, currW);

    return p = max(take, leave);
}

int calcIteriative(){
    for (int i = n - 1; i >= 0; i--) {
        for (int currW = 0; currW <= w; currW++) {
            int leave = dp[i + 1][currW];
            int take = (currW + a[i].w <= w ? dp[i + 1][currW + a[i].w] + a[i].v : -INF);
            dp[i][currW] = max(leave, take);
        }
    }
    return dp[0][0];
}

void solve() {
    // memset(dp, -1, sizeof(dp));
    cin >> n >> w;
    a.resize(n);

    for (int i = 0; i < n; i++){
        cin >> a[i].w >> a[i].v;
    }
 
    cout << calcIteriative();
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