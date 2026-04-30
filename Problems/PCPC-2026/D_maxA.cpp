// D. maxA
// URL: https://codeforces.com/group/Rilx5irOux/contest/640620/problem/D
// Time: 4/29/2026, 8:17:49 PM
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

int n, m, k;

void prefixSum2D(vector<vi> &a) {
    for (int i = 0; i <= n; i++) 
        for (int j = 1; j <= m; j++) 
            a[i][j] += a[i][j - 1];    
    for (int i = 0; i <= m; i++) 
        for (int j = 1; j <= n; j++) 
            a[j][i] += a[j - 1][i];
}

int sumOfArea(int x1, int y1, int x2, int y2, vector<vi>& a) {
    return a[x2][y2] 
         - a[x1 - 1][y2]
         - a[x2][y1 - 1]
         + a[x1 - 1][y1 - 1];
}

void solve() {
    cin >> n >> m >> k;
    
    vector<vi> matrix(n + 1, vi(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int x; cin >> x;
             matrix[i][j] = (x <= k? 1 : 0);
        }
    }

    prefixSum2D(matrix);

    int l = 0, r = n * m + 1;
    while (l + 1 < r) {
        int length = (l + r)/2;
        int count = length * length;
        
        bool can = false;
        for (int i = 1; i + length - 1 <= n; i++) {
            for (int j = 1; j + length - 1 <= m; j++) {
                int sum = sumOfArea(i, j, i + length - 1, j + length - 1, matrix);
                if(sum >= (count + 1) / 2) {
                    can = true;
                    break;
                } 
            }
            if(can) break;
        }

        if(can) l = length;
        else r = length;
    }

    cout << l * l << "\n";
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