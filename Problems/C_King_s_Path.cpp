/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// C. King's Path
// URL: https://codeforces.com/contest/242/problem/C
// Time: 5/22/2025, 2:42:22 PM
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

int  dx[] = {-1,   1,   0,   0,  1,  -1,  1, -1};
int  dy[] = { 0,   0,  -1,   1,  1,  -1, -1,  1};
char dr[] = {'U', 'D', 'L', 'R'};

void Ramez() {
    int x, y; cin >> x >> y; pii start = {x, y};
    int xd, yd; cin >> xd >> yd; pii target = {xd, yd};

    int n; cin >> n;
    map<pii, int> vis;
    for (int i = 0; i < n; i++){
        int r, u, v; cin >> r >> u >> v;
        for (int j = u; j <= v; j++){
            vis[{r, j}] = 0;
        }
    }

    queue<pii> q; q.push(start);
    while(!q.empty()){
        pii u = q.front(); q.pop();
        
        if(u == target){
            cout << vis[u];
            return;
        }

        for (int i = 0; i < 8; i++){
            pii v = {u.first + dx[i], u.second + dy[i]};
            if(!vis.count(v) || vis[v]) continue;
            vis[v] = vis[u] + 1;
            q.push(v);
        }
    }

    cout << "-1\n";
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