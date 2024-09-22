// Ramez Medhat
// problem: D. Xenia and Bit Operations
// URL: https://codeforces.com/contest/339/problem/D  
// Start: 7/15/2024, 3:29:27 PM
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
struct SegTree;
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

const int MOD = 1000000007;

struct SegTree {
    int size;
    vll tree;
    int vecSize;

private:
    bool build(vi& a, int currentNode, int l, int r) {
        if (r - l == 1) { // we're in the bottom of the tree
            if (l < a.size()) { // check that we're in range of the a elements
                tree[currentNode] = a[l];
            }
            return true;
        }

        int mid = (l + r) / 2; 
        bool OR = build(a, 2 * currentNode + 1, l, mid); // build left
        OR = build(a, 2 * currentNode + 2, mid, r); // build right
        if (OR) {
            tree[currentNode] = tree[2 * currentNode + 1] | tree[2 * currentNode + 2]; // OR operation
        } else {
            tree[currentNode] = tree[2 * currentNode + 1] ^ tree[2 * currentNode + 2]; // XOR operation
        }
        return !OR;
    }

    bool set(int i, int v, int currentNode, int l, int r) {
        if (r - l == 1) { // we're in the bottom of the tree
            tree[currentNode] = v; return true;
        }

        bool OR;
        int mid = (l + r) / 2;
        if (i < mid) { // go left
            OR = set(i, v, 2 * currentNode + 1, l, mid);
        }
        else {  // go right
            OR = set(i, v, 2 * currentNode + 2, mid, r);
        }
        if (OR) {
            tree[currentNode] = tree[2 * currentNode + 1] | tree[2 * currentNode + 2]; // OR operation
        } else {
            tree[currentNode] = tree[2 * currentNode + 1] ^ tree[2 * currentNode + 2]; // XOR operation
        }
        return !OR;
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

    ll top() {
        return tree[0];
    }
};

void solve() {
    int n, m; 
    cin >> n >> m;
    n = pow(2, n);
    vi a(n); 
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    SegTree st(n, a);
    while (m--) {
        int i, v;
        cin >> i >> v;
        st.setValueAtIndex(i - 1, v);
        cout << st.top() << "\n";
    }
}

/*
NOTES:
 first it: OR's the numbers
 second it: XOR's the numbers
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

