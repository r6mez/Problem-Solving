// Ramez Medhat
// problem: C. Number of Minimums on a Segment
// URL: https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/C  
// Start: 7/13/2024, 4:18:36 PM
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

struct Item
{
    ll v; // value (minimum)
    ll c; // count
};

struct SegTree {
    int size;
    vector<Item> tree;

private:

    Item merge(Item a, Item b){
        if(a.v < b.v) return a;
        if(b.v < a.v) return b;
        return {a.v, a.c + b.c};
    }

    Item single(int v){
        return {v, 1};
    }

    void build(vi& a, int currentNode, int l, int r) {
        if (r - l == 1) { // we're in the bottom of the tree
            if (l < a.size()) { // check that we're in range of the a elements
                tree[currentNode] = single(a[l]);
            }
            return;
        }

        int mid = (l + r) / 2;
        build(a, 2 * currentNode + 1, l, mid); // build left
        build(a, 2 * currentNode + 2, mid, r); // build right
        tree[currentNode] = merge(tree[2 * currentNode + 1], tree[2 * currentNode + 2]); // merge results
    }

    Item calc(int l, int r, int currentNode, int curL, int curR) {
        if (curL >= r || curR <= l) return {LLONG_MAX, 0}; // don't intersect
        if (curL >= l && curR <= r) return tree[currentNode]; // fully intersect

        int mid = (curL + curR) / 2;
        Item leftPart = calc(l, r, 2 * currentNode + 1, curL, mid);
        Item rightPart = calc(l, r, 2 * currentNode + 2, mid, curR);
        return merge(leftPart, rightPart);
    }

    void set(int i, int v, int currentNode, int l, int r) {
        if (r - l == 1) { // we're in the bottom of the tree
            tree[currentNode] = single(v); return;
        }

        int mid = (l + r) / 2;
        if (i < mid) { // go left
            set(i, v, 2 * currentNode + 1, l, mid);
        }
        else {  // go right
            set(i, v, 2 * currentNode + 2, mid, r);
        }
        tree[currentNode] = merge(tree[2 * currentNode + 1], tree[2 * currentNode + 2]); // merge results
    }

public:
    SegTree(int n, vi& a) {
        size = 1;
        while (size < n) size *= 2;
        tree.resize(2 * size);
        // build
        build(a, 0, 0, size);
    }

    void setValueAtIndex(int i, int v) {
        set(i, v, 0, 0, size);
    }

    Item minOfRange(int l, int r) {
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
            Item ans = st.minOfRange(l, r);
            cout << ans.v << " " << ans.c << "\n";
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