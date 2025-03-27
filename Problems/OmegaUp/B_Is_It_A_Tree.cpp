/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all that remained were fields of dreamless solitude.
*/
// B. Is It A Tree
// URL: https://omegaup.com/arena/gsoc2025/practice/#problems/IsItATree
// Time: 3/3/2025, 10:24:31 PM
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

void Ramez() {
    map<int, vi> adj; map<int, int> inDeg;

    auto isTree = [&]() {
        int root = -1;
        for (auto& [node, deg] : inDeg) {
            if (deg == 0) {
                if (root == -1) root = node;
                else return false; 
            }
        }

        queue<int> q; q.push(root);
        map<int, bool> vis;
        while (!q.empty()) {
            int parent = q.front(); q.pop();
            if (vis[parent]) return false;

            vis[parent] = true;
            for (int child : adj[parent]) q.push(child);
        }

        return (vis.size() == inDeg.size() || root != -1);
    };

    int t = 1, x, y;
    while (cin >> x >> y) {
        if (x == 0 && y == 0) {
            if (adj.empty() || isTree()) cout << "Case " << t++ << " is a tree." << endl;
            else cout << "Case " << t++ << " is not a tree." << endl;
            adj.clear(); inDeg.clear();
        } else if (x == -1 && y == -1) {
            break;
        } else {
            if (!inDeg.count(x)) inDeg[x] = 0;
            if (!inDeg.count(y)) inDeg[y] = 0;
            adj[x].push_back(y);
            inDeg[y]++;
        }
    }
}

int32_t main() {
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}
