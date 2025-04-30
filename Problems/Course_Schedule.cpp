/*
    I thought I could bring an end to the world's suffering,
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// Course Schedule
// URL: https://cses.fi/problemset/task/1679
// Time: 4/30/2025, 3:44:17 PM
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

//A topological sort takes a directed acyclic graph (DAG) and produces 
//a linear ordering of its vertices such that for every directed edge
// u → v, u comes before v in that order.
// Returns a vector of nodes in a valid order; if a cycle exists, the size will be < n. 
// useful for: Scheduling with Dependencies, Course Prerequisites, 
vi topologicalSort(int n, vector<vi>& adj, vi& inDeg) {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (inDeg[i] == 0)
            q.push(i);
    }

    vi order;

    while (!q.empty()) {
        int parent = q.front(); q.pop();
        order.push_back(parent);
        for (int child : adj[parent]) {
            if (--inDeg[child] == 0)
                q.push(child);
        }
    }
    
    return order;
}

void Ramez() {
    int n, m; cin >> n >> m;
    vector<vi> adj(n + 1);
    vi inDeg(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b; 
        cin >> a >> b;
        adj[a].push_back(b);
        inDeg[b]++;
    }

    vi order = topologicalSort(n, adj, inDeg);

    if (order.size() < n) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    for (int c : order) 
        cout << c << ' ';
    cout << '\n';
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