// D. Falfoul's Snowy Slide
// URL: https://codeforces.com/gym/584099/problem/D
// Time: 2/1/2025, 1:32:28 PM
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi   vector<int>
#define pii  pair<int, int>
#define all(v)  v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
int  dx[] = { -1,   1,   0,   0 }; int  dy[] = { 0,   0,  -1,   1 }; char dir[] = { 'U', 'D', 'L', 'R' };
int MOD = 1000000007;

void dfs(int x, int y, unordered_map<int, vi> &rows, unordered_map<int, vi> &cols, set<pii> &visited){
    if (visited.count({x, y})) return;

    visited.insert({x, y});

    for (int yy : rows[x]) dfs(x, yy, rows, cols, visited);
    for (int xx : cols[y]) dfs(xx, y, rows, cols, visited);
}


void Solve() {
    int n; cin >> n;

    vector<pii> points(n);

    for (int i = 0; i < n; i++){
        cin >> points[i].first >> points[i].second;
    }
    

    unordered_map<int, vi> rows, cols;
    for (auto [x, y] : points) {
        rows[x].push_back(y);
        cols[y].push_back(x);
    }

    set<pii> visited;

    int components = 0;
    for (auto [x, y] : points) {
        if (!visited.count({x, y})) {
            components++;
            dfs(x, y, rows, cols, visited);
        }
    }

    cout << components - 1 << "\n";
}

/*
NOTES:

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Solve();
    return 0;
}