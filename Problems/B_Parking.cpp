/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// B. Parking
// URL: https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/B
// Time: 6/22/2025, 4:05:54 PM
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
    vector<int> parent, rank, size;
    int c;

    DSU(int n) : parent(n + 1), rank(n + 1, 0), size(n + 1, 1), c(n) {
        for (int i = 1; i <= n; ++i) parent[i] = i;
    }

    int find(int i) {
        return (parent[i] == i ? i : (parent[i] = find(parent[i])));
    }

    bool same(int i, int j) {
        return find(i) == find(j);
    }

    int get_size(int i) {
        return size[find(i)];
    }

    // number of connected components
    int count() {
        return c;    
    }

    int merge(int i, int j) {
        if ((i = find(i)) == (j = find(j))) return -1;
        else --c;

        if (rank[i] > rank[j]) swap(i, j);
        parent[i] = j;
        size[j] += size[i];
        if (rank[i] == rank[j]) rank[j]++;
        
        return j;
    }
};

void Ramez() {
    int n; cin >> n;
    DSU dsu(n);

    for (int i = 0; i < n; ++i) {
        int p; cin >> p;
        int freeSlot = dsu.find(p);
        cout << freeSlot << " ";
        dsu.parent[freeSlot] = dsu.find((freeSlot % n) + 1);
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