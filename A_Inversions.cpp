// Ramez Medhat
// problem: A. Inversions
// URL: https://codeforces.com/edu/course/2/lesson/4/3/practice/contest/274545/problem/A  
// Start: 7/13/2024, 10:30:27 PM
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
            tree[currentNode] = 1; return;
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

    ll calc(int l, int r, int currentNode, int curL, int curR) {
        if (curL >= r || curR <= l) return 0; // don't intersect
        if (curL >= l && curR <= r) return tree[currentNode]; // fully intersect

        int mid = (curL + curR) / 2;
        ll calcLeft = calc(l, r, 2 * currentNode + 1, curL, mid);
        ll calcRight = calc(l, r, 2 * currentNode + 2, mid, curR);
        return calcLeft + calcRight;
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

    ll sumOfRange(int l, int r) {
        return calc(l, r, 0, 0, size);
    }
};

void solve() {
    int n; cin >> n;
    vi a(n);
    SegTree st(n, a);


    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        cout << st.sumOfRange(x, n) << " ";
        st.switchIndex(x-1);
    }
}

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
