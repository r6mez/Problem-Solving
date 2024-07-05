// Ramez Medhat
// problem: D - King Supremacy
// URL: https://vjudge.net/contest/638602#problem/D  
// Start: 7/5/2024, 5:39:43 PM
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
    int ans = ceil(n/2.0) * ceil(m/2.0);
    cout << ans << "\n";
}

/*
NOTES:

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

void dfs(int parent, vector<vi> &graph, vector<bool> &visited){
    if(visited[parent]) return;
    
    visited[parent] = true;
    for(int child : graph[parent]){
        dfs(child, graph, visited);
    }
}