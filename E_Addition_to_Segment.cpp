// Ramez Medhat
// problem: E. Addition to Segment
// URL: https://codeforces.com/edu/course/2/lesson/4/3/practice/contest/274545/problem/E  
// Start: 7/14/2024, 7:25:12 PM
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
    void set(int i, int v, int currentNode, int l, int r) {
        if (r - l == 1) { // we're in the bottom of the tree
            tree[currentNode] += v; return;
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
    SegTree(int n, vll& a) {
        size = 1;
        while (size < n) size *= 2;
        tree.resize(2 * size, 0LL);
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


void solve() {
    int n, m; cin >> n >> m;
    vll a(n);
    SegTree st(n,a);
    
    while (m--){
        int op; cin >> op;
        if(op == 1){
            int l, r, v; cin >> l >> r >> v;
            st.setValueAtIndex(l, v);
            st.setValueAtIndex(r, -v);
        } else {
            int i; cin >> i;
            cout << st.sumOfRange(0, i+1) << "\n";
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

