// Ramez Medhat
// problem: A. Segment with the Maximum Sum
// URL: https://codeforces.com/edu/course/2/lesson/4/2/practice/contest/273278/problem/A  
// Start: 7/13/2024, 6:13:56 PM
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

struct Node {
    ll sum, max_prefix, max_suffix, max_subarray;

    Node() : sum(0), max_prefix(0), max_suffix(0), max_subarray(0) {}
    Node(ll value) : sum(value), max_prefix(max(0LL, value)), max_suffix(max(0LL, value)), max_subarray(max(0LL, value)) {}
};

struct SegTree {
    int size;
    vector<Node> tree;

private:
    Node combine(const Node& left, const Node& right) {
        Node result;
        result.sum = left.sum + right.sum;
        result.max_prefix = max(left.max_prefix, left.sum + right.max_prefix);
        result.max_suffix = max(right.max_suffix, right.sum + left.max_suffix);
        result.max_subarray = max({ left.max_subarray, right.max_subarray, left.max_suffix + right.max_prefix });
        return result;
    }

    void build(vi& a, int currentNode, int l, int r) {
        if (r - l == 1) { // we're in the bottom of the tree
            if (l < a.size()) { // check that we're in range of the a elements
                tree[currentNode] = Node(a[l]);
            }
            return;
        }

        int mid = (l + r) / 2;
        build(a, 2 * currentNode + 1, l, mid); // build left
        build(a, 2 * currentNode + 2, mid, r); // build right
        tree[currentNode] = combine(tree[2 * currentNode + 1], tree[2 * currentNode + 2]);
    }

    void set(int i, int v, int currentNode, int l, int r) {
        if (r - l == 1) { // we're in the bottom of the tree
            tree[currentNode] = Node(v); return;
        }

        int mid = (l + r) / 2;
        if (i < mid) { // go left
            set(i, v, 2 * currentNode + 1, l, mid);
        }
        else {  // go right
            set(i, v, 2 * currentNode + 2, mid, r);
        }
        tree[currentNode] = combine(tree[2 * currentNode + 1], tree[2 * currentNode + 2]);
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

    ll maxSubarraySum() {
        return tree[0].max_subarray;
    }
};

void solve() {
    int n, m; cin >> n >> m;
    vi a(n); cin >> a;
    SegTree st(n, a);


    cout << st.maxSubarraySum() << "\n";
    while (m--) {
        int i, v; cin >> i >> v;
        st.setValueAtIndex(i, v);
        cout << st.maxSubarraySum() << endl;
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