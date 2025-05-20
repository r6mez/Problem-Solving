/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// C. Circular RMQ
// URL: https://codeforces.com/contest/52/problem/C
// Time: 5/19/2025, 9:37:15 PM
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

const int inf = -LLONG_MAX;
struct Node {
    Node* l = 0, * r = 0;
    int lo, hi, mset = inf, madd = 0, val = -inf;
    Node(int lo, int hi) : lo(lo), hi(hi) {} 
    Node(vector<int>& v, int lo, int hi) : lo(lo), hi(hi) {
        if (lo + 1 < hi) {
            int mid = lo + (hi - lo) / 2;
            l = new Node(v, lo, mid);
            r = new Node(v, mid, hi);
            val = min(l->val, r->val);
        }
        else
            val = v[lo];
    }
    int query(int L, int R) {
        if (R <= lo || hi <= L)
            return -inf;
        if (L <= lo && hi <= R)
            return val;
        push();
        return min(l->query(L, R), r->query(L, R));
    }
    void set(int L, int R, int x) {
        if (R <= lo || hi <= L)
            return;
        if (L <= lo && hi <= R)
            mset = val = x, madd = 0;
        else {
            push(), l->set(L, R, x), r->set(L, R, x);
            val = min(l->val, r->val);
        }
    }
    void add(int L, int R, int x) {
        if (R <= lo || hi <= L)
            return;
        if (L <= lo && hi <= R) {
            if (mset != inf)
                mset += x;
            else
                madd += x;
            val += x;
        }
        else {
            push(), l->add(L, R, x), r->add(L, R, x);
            val = min(l->val, r->val);
        }
    }
    void push() {
        if (!l) {
            int mid = lo + (hi - lo) / 2;
            l = new Node(lo, mid);
            r = new Node(mid, hi);
        }
        if (mset != inf)
            l->set(lo, hi, mset), r->set(lo, hi, mset), mset = inf;
        else if (madd)
            l->add(lo, hi, madd), r->add(lo, hi, madd), madd = 0;
    }
};

void Ramez() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    Node* root = new Node(v, 0, n);

    int q;
    cin >> q;
    string s;
    int l, r;
    int x;
    cin.ignore();
    while (q--) {
        getline(cin, s);
        stringstream ss(s);
        ss >> l >> r;
        if (l > r) {
            if (ss >> x) {
                root->add(l, n, x);
                root->add(0, r + 1, x);
            }
            else {
                int ans = root->query(l, n);
                ans = min(ans, root->query(0, r + 1));
                cout << ans << "\n";
            }
            continue;
        }
        if (ss >> x) {
            root->add(l, r + 1, x);
        }
        else {
            int ans = root->query(l, r + 1);
            cout << ans << "\n";
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