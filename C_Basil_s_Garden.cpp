// Ramez Medhat
// problem: C. Basil's Garden
// URL: https://codeforces.com/problemset/problem/1987/C  
// Start: 7/15/2024, 6:43:11 PM
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

void solve() {
    int n; cin >> n;
    vi a(n); cin >> a;

    if(n == 1) {
        cout << a[0] << "\n";
        return;
    }

    for (int i = n - 2; i >= 0; i--) {
        a[i] = max(a[i], a[i+1]+1);
    }

    cout << a[0] << "\n";
}

/*
NOTES:

*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
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

    ll get(int x, int currentNode, int l, int r) {
        if (tree[currentNode] < x) {
            return -1;
        }

        if (r - l == 1) { // we're in the bottom of the tree
            return l;
        }

        int mid = (l + r) / 2;
        int res = get(x, 2 * currentNode + 1, l, mid);
        if (res == -1) {
            res = get(x, 2 * currentNode + 2, mid, r);
        }
        return res;
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

    ll sumOfRange(int l, int r) {
        return calc(l, r, 0, 0, size);
    }

    ll getFirstXIndex(int x) {
        return get(x, 0, 0, size);
    }
};