// H. killers
// URL: https://codeforces.com/group/Rilx5irOux/contest/686782/problem/H
// Time: 5/25/2026, 3:47:46 PM
#include <bits/stdc++.h>
#include <climits>
#include <cstring>
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

int n; 
vector<pii> points;

int dp[1010][1010];

int go(int i, int j){
    int k = j != 1001? max(i , j) + 1 : i + 1;
    // cout << i << " " << k << "\n";
    if(k >= n) return dp[i][j] = 0;
    if(j != 1001 && dp[i][j] != LLONG_MAX) return dp[i][j];
    
    int cost2 = 0; 
    if(j != 1001){
        cost2 = abs(points[j].first - points[k].first) + abs(points[j].second - points[k].second);    
    }

    int cost1 = abs(points[i].first - points[k].first) + abs(points[i].second - points[k].second);
    
    return dp[i][j] = min(go(k, j) + cost1, go(i, k) + cost2);
}

void solve() {
    for(int i = 0; i < 1010; i++){
        for(int j = 0; j < 1010; j++){
            dp[i][j] = LLONG_MAX;
        }
    }

    cin >> n;
    points.resize(n);
    for(auto &[x, y] : points){
        cin >> x >> y;
    }

    if(n <= 2) finish(0);

    cout << go(0, 1001);
}

/*

*/

signed main() {
    // UseFile();
    // FastIO();
    int t = 1;
    // cin >> t;
    while (t--) solve();
}