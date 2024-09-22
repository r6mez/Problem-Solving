// Ramez Medhat
// problem: B. Corner Twist
// URL: https://codeforces.com/contest/1983/problem/B  
// Start: 7/7/2024, 5:50:28 PM
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <numeric>
using namespace std;
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vll vector<long long>
#define all(v)  v.begin(), v.end()
#define search(vec, item) find(all(vec), item) != vec.end()
vector<vi> repGraph(int n, int m);
void dfs(int parent, vector<vi>& graph, vector<bool>& visited);
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for (const auto& i : v) os << i << ' ';
    return os;
}
template<typename T>
istream& operator>>(istream& is, vector<T>& v) {
    for (auto& i : v) is >> i;
    return is;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    vector<vector<int>> brr(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            arr[i][j] = c - '0';
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            brr[i][j] = c - '0';
        }
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            while (arr[i][j] != brr[i][j]) {
                arr[i][j] = (arr[i][j] + 1) % 3;
                arr[i + 1][j] = (arr[i + 1][j] + 2) % 3;
                arr[i][j + 1] = (arr[i][j + 1] + 2) % 3;
                arr[i + 1][j + 1] = (arr[i + 1][j + 1] + 1) % 3;
            }
        }
    }

    bool Can = true;
    for (int i = 0; i < n; i++)
        Can &= (arr[i][m - 1] == brr[i][m - 1]);

    for (int j = 0; j < m; j++)
        Can &= (arr[n - 1][j] == brr[n - 1][j]);

    cout << (Can ? "YES\n" : "NO\n");
}



/*
2 7
0000000
0100010
2220111
1210202

00
00

12
21

21
12


*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

vector<vi> repGraph(int n, int m) {
    vector<vi> graph(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    return graph;
}

void dfs(int parent, vector<vi>& graph, vector<bool>& visited) {
    if (visited[parent]) return;

    visited[parent] = true;
    for (int child : graph[parent]) {
        dfs(child, graph, visited);
    }
}