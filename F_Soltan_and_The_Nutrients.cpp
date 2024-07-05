// Ramez Medhat
// problem: F - Soltan and The Nutrients
// URL: https://vjudge.net/contest/638602#problem/F  
// Start: 7/5/2024, 5:31:33 PM
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
void dfs(int parent, vector<vi> &graph, vector<bool> &visited);
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
    vi a(m); cin >> a;
    vector<vi> x(n, vi(m));
    for (int i = 0; i < n; i++){
        cin >> x[i];
    }

    vi ate(m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ate[j] += x[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        if(ate[i] < a[i]) {
            cout << "No\n";
            return;
        }
    }
    
    cout << "Yes\n";
}

/*
NOTES:

*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
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

void dfs(int parent, vector<vi> &graph, vector<bool> &visited){
    if(visited[parent]) return;
    
    visited[parent] = true;
    for(int child : graph[parent]){
        dfs(child, graph, visited);
    }
}