// Ramez Medhat
// problem: B. K-th one
// URL: https://codeforces.com/edu/course/2/lesson/4/2/practice/contest/273278/problem/B  
// Start: 7/13/2024, 7:13:39 PM
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
        tree[currentNode] = tree[2 * currentNode + 1] + tree[2 * currentNode + 2]; // calc sum
    }

    void set(int i, int currentNode, int l, int r) {
        if (r - l == 1) { // we're in the bottom of the tree
            tree[currentNode] = !tree[currentNode]; return;
        }

        int mid = (l + r) / 2;
        if (i < mid) { // go left
            set(i, 2 * currentNode + 1, l, mid);
        }
        else {  // go right
            set(i, 2 * currentNode + 2, mid, r);
        }
        tree[currentNode] = tree[2 * currentNode + 1] + tree[2 * currentNode + 2];
    }


    int get(int k, int currentNode, int l, int r) {
        if (r - l == 1) { // we're in the bottom of the tree
            return l;
        }

        int mid = (l + r) / 2;
        if (tree[2 * currentNode + 1] > k) { // go left
            return get(k, 2 * currentNode + 1, l, mid);
        }
        else {  // go rights
            return get(k - tree[2 * currentNode + 1], 2 * currentNode + 2, mid, r);
        }
    }

public:
    SegTree(int n, vi& a) {
        size = 1;
        while (size < n) size *= 2;
        tree.resize(2 * size, 0LL);

        // build
        build(a, 0, 0, size);
    }

    void switchIndex(int i) {
        set(i, 0, 0, size);
    }


    int getKthOneIndex(int k) {
        return get(k, 0, 0, size);
    }
};

void solve() {
    int n, m; cin >> n >> m;
    vi a(n); cin >> a;
    SegTree st(n, a);


    while (m--) {
        int op; cin >> op;
        if (op == 1) {
            int i; cin >> i;
            st.switchIndex(i);
        }
        else {
            int k; cin >> k;
            cout << st.getKthOneIndex(k) << "\n";
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