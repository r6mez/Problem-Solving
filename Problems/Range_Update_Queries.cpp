/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// Range Update Queries
// URL: https://cses.fi/problemset/task/1651
// Time: 5/18/2025, 1:59:06 PM
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

template<typename T>
struct Fenwick {
    int n;
    vector<T> B1, B2;
    static constexpr T unit = T(0);
    T f(T& a, T& b) { return a + b; }
    Fenwick(int size) : n(size), B1(size + 1, unit), B2(size + 1, unit) {}

private:
    void updateBIT(vector<T>& B, int i, T v) {
        for (; i <= n; i += i & -i) B[i] = f(B[i], v);
    }

    T prefixSum(int x) {
        T sum1 = unit, sum2 = unit;
        for (int i = x; i > 0; i -= i & -i) {
            sum1 = f(sum1, B1[i]);
            sum2 = f(sum2, B2[i]);
        }
        return sum1 * x - sum2;
    }

public:
    void rangeAdd(int l, int r, T v) {
        updateBIT(B1, l, v);
        updateBIT(B1, r + 1, -v);
        updateBIT(B2, l, v * (l - 1));
        updateBIT(B2, r + 1, -v * r);
    }

    T rangeSum(int l, int r) {
        return prefixSum(r) - prefixSum(l - 1);
    }
};



void Ramez() {
    int n, q; cin >> n >> q;
    vi a(n); cin >> a;

    Fenwick<int> t(n);
    for (int i = 1; i <= n; i++) {
        t.rangeAdd(i, i, a[i - 1]);
    }

    while (q--) {
        int ops; cin >> ops;
        if (ops == 1) {
            int a, b, u; cin >> a >> b >> u;
            t.rangeAdd(a, b, u);
        }
        else {
            int k; cin >> k;
            cout << t.rangeSum(k, k) << "\n";
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