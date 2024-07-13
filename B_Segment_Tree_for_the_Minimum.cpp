// Ramez Medhat
// problem: B. Segment Tree for the Minimum
// URL: https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/B  
// Start: 7/13/2024, 4:03:30 PM
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
const int MOD = 1000000007;
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

struct SegTree {
    int size;
    vll tree;

private:
    // Note: childs of currentNode = (2*currentNode + 1 left) and (2*currentNode + 2 right)
    // Note: int l, int r parameters is the range of the vector where the currentNode has as childern
    // Note when r-l == 1 then we're in the bottom of the tree
    void build(vi& a, int currentNode, int l, int r) {
        if (r - l == 1) { // we're in the bottom of the tree
            if (l < a.size()) { // check that we're in range of the a elements
                tree[currentNode] = a[l];
            }
            return;
        }

        int mid = (l + r) / 2;
        build(a, 2 * currentNode + 1, l, mid); // build left
        build(a, 2 * currentNode + 2, mid, r); // build right
        tree[currentNode] = min(tree[2 * currentNode + 1], tree[2 * currentNode + 2]); // calc sum
    }

    ll calc(int l, int r, int currentNode, int curL, int curR) {
        if (curL >= r || curR <= l) return INT_MAX; // don't intersect
        if (curL >= l && curR <= r) return tree[currentNode]; // fully intersect

        int mid = (curL + curR) / 2;
        ll minLeft = calc(l, r, 2 * currentNode + 1, curL, mid);
        ll minRight = calc(l, r, 2 * currentNode + 2, mid, curR);
        return min(minLeft, minRight);
    }

    void set(int i, int v, int currentNode, int l, int r) {
        if (r - l == 1) { // we're in the bottom of the tree
            tree[currentNode] = v; return;
        }

        int mid = (l + r) / 2;
        if (i < mid) { // go left
            set(i, v, 2 * currentNode + 1, l, mid);
        }
        else {  // go right
            set(i, v, 2 * currentNode + 2, mid, r);
        }
        tree[currentNode] = min(tree[2 * currentNode + 1], tree[2 * currentNode + 2]); // calc sum
    }

public:
    SegTree(int n, vi& a) {
        size = 1;
        while (size < n) size *= 2;
        tree.resize(2 * size, 0LL);

        // build
        build(a, 0, 0, size);
    }

    void setValueAtIndex(int i, int v) {
        set(i, v, 0, 0, size);
    }

    ll minOfRange(int l, int r) {
        return calc(l, r, 0, 0, size);
    }
};

void solve() {
    int n, m; cin >> n >> m;
    vi a(n); cin >> a;
    SegTree st(n, a);

    while (m--) {
        int op; cin >> op;
        if (op == 1) {
            int i, v; cin >> i >> v;
            st.setValueAtIndex(i, v);
        }
        else {
            int l, r; cin >> l >> r;
            cout << st.minOfRange(l, r) << "\n";
        }
    }
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