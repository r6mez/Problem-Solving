/*
    One day, I'm gonna grow wings
*/
// C. Fox And Names
// URL: https://codeforces.com/problemset/problem/510/C
// Time: 8/22/2025, 5:30:38 PM
#include <bits/stdc++.h>
using namespace std;
#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> auto& operator<<(auto& o, vector<T>& v) { for (auto& e : v) o << e << ' '; return o; }
template<typename T> auto& operator>>(auto& i, vector<T>& v) { for (auto& e : v) i >> e; return i; }
void FastIO() { cin.tie(nullptr)->sync_with_stdio(false); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007;

// A topological sort takes a directed acyclic graph (DAG) and produces 
// a linear ordering of its vertices such that for every directed edge
// u → v, u comes before v in that order.
// Returns a vector of nodes in a valid order; if a cycle exists, the size will be < n. 
// useful for: Scheduling with Dependencies, Course Prerequisites, 
vi topologicalSort(int n, vector<vi>& adj, vi& inDeg) {
    queue<int> q;
    for (int i = 0; i < n; i++) {
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

void solve() {
    int n; cin >> n;
    vector<string> words(n); cin >> words;
    vector<vi> adj(26);
    vi inDeg(26);

    for (int i = 0; i < n - 1; i++){
        if(words[i].substr(0, words[i + 1].size()) == words[i + 1]){
            cout << "Impossible\n";
            return;
        }

        for (int j = 0; j < words[i].size(); j++){
            if(j < words[i + 1].size() && words[i][j] != words[i + 1][j]){
                int u = words[i][j] - 'a', v = words[i + 1][j] - 'a';
                adj[u].push_back(v);
                inDeg[v]++;
                break;
            } 
        }
    }
    
    vi order = topologicalSort(26, adj, inDeg);

    if(order.size() < 26){
        cout << "Impossible\n";
        return;
    }

    for (int i = 0; i < 26; i++){
        cout << char(order[i] + 'a');
    }
}

/*
    If there's a cycle then there's no solution
    then we just perform a topo sort.
    NOTE: if there's a word and then a prefix of it, the answer is impossible
    example this test case:
    2
    aa
    a
*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) solve();
}