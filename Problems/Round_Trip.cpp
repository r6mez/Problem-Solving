// Ramez Medhat
// problem: Round Trip
// URL: https://cses.fi/problemset/task/1669  
// Start: 7/4/2024, 5:57:58 PM
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

int repeatedNode = 0;
vi cycle;
bool found = false;

bool dfs(int node, int parent, vector<vi>& graph, vector<int>& visited, vector<int>& parentTrack) {
    visited[node] = 1;
    parentTrack[node] = parent;

    for (int child : graph[node]) {
        if (child == parent) continue;
        if (visited[child] == 0) {
            if (dfs(child, node, graph, visited, parentTrack)) {
                return true;
            }
        } else if (visited[child] == 1) {
            repeatedNode = child;
            cycle.push_back(child);
            int current = node;
            while (current != child) {
                cycle.push_back(current);
                current = parentTrack[current];
            }
            cycle.push_back(child);
            reverse(cycle.begin(), cycle.end());
            return true;
        }
    }

    visited[node] = 2;
    return false;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vi> graph = repGraph(n, m);

    vector<int> visited(n + 1);
    vector<int> parentTrack(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        if (dfs(i, -1, graph, visited, parentTrack)) {
            cout << cycle.size() << endl;
            for (int node : cycle) {
                cout << node << " ";
            }
            cout << endl;
            return;
        }
    }

    cout << "IMPOSSIBLE\n";
}


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
    vector<vi> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    return graph;
}
