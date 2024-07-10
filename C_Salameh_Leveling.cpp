// Ramez Medhat
// problem: C. Salameh Leveling
// URL: https://codeforces.com/group/qxlLGDBwj5/contest/530328/problem/C  
// Start: 7/10/2024, 3:09:51 PM
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
    int n, m, k; cin >> n >> m >> k;
    priority_queue<pair<ll, ll>> pq;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ll x; cin >> x;
            pq.push({x, j});
        }
    }

    vi js(m);
    for (int i = 0; i < m; i++) {
        js[i] = i + 1; 
    }

    ll sum = 0;
    while (!pq.empty()) {
        auto [box, j] = pq.top(); pq.pop();
        if (box <= 0 || k <= 0) break; 
        if (js[j] <= 0) continue; 

        sum += box;
        js[j]--;
        k--;
    }

    cout << sum << "\n";
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

void dfs(int parent, vector<vi>& graph, vector<bool>& visited) {
    if (visited[parent]) return;

    visited[parent] = true;
    for (int child : graph[parent]) {
        dfs(child, graph, visited);
    }
}