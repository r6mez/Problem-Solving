/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// C. Experience
// URL: https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/C
// Time: 6/27/2025, 7:05:44 PM
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

struct DSU {
    vector<int> parent, points, size;
    int count; // of component

    DSU(int n) : parent(n + 1),  points(n + 1, 0), size(n + 1, 1), count(n) { iota(all(parent), 0); }

    int find(int i) { return (parent[i] == i ? i : find(parent[i])); }

    bool same(int i, int j) { return find(i) == find(j); }

    int getSize(int i) { return size[find(i)]; }
    int getPoints(int i) { 
        if(parent[i] == i){
            return points[i];
        }
        return points[i] + getPoints(parent[i]);
    }

    void add(int u, int value){
        points[find(u)] += value;
    }

    int merge(int child, int daddy) {
        if ((child = find(child)) == (daddy = find(daddy))) return -1;
        else --count;
        if (size[child] > size[daddy]) swap(child, daddy);
        parent[child] = daddy;
        points[child] -= points[daddy];
        size[daddy] += size[child];        
        return daddy;
    }
};

void Ramez() {
    int n, m; cin >> n >> m;
    DSU dsu(n);
    while(m--){
        int u, v;
        string s; cin >> s >> u;
        if(s == "join"){
            cin >> v;
            dsu.merge(u, v);
        }

        if(s == "add"){
            cin >> v;
            dsu.add(u, v);
        }

        if(s == "get"){
            cout << dsu.getPoints(u) << "\n";
        }
    }
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