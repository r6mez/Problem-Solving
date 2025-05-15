/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// E. Enemy is weak
// URL: https://codeforces.com/contest/61/problem/E
// Time: 5/12/2025, 10:54:33 PM
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

struct SegTree {
    typedef int T;
    static constexpr T unit = 0;
    T f(T a, T b) { return a + b; } // (any associative fn)
    vector<T> s; int n;
    SegTree(int n = 0, T def = unit) : s(2 * n, def), n(n) {}
    void update(int pos, T val) {
        for (s[pos += n] = val; pos /= 2;)
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }
    T query(int b, int e) { // query [b, e)
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, s[b++]);
            if (e % 2) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};

void Ramez() {
    int n; cin >> n;
    vi a(n); cin >> a;
    vector<pii> pos;
    for (int i = 0; i < n; i++){
        pos.push_back({a[i], i});
    }
    
    sort(all(pos));

    SegTree st1(n, 0);
    vi gb(n);
    for (int i = 0; i < n; i++) {
        gb[i] = st1.query(pos[i].second, n);
        st1.update(pos[i].second, 1);
    }

    SegTree st2(n, 0);
    vi la(n);
    for (int i = n - 1; i >= 0; i--) {
        la[i] = st2.query(0, pos[i].second);
        st2.update(pos[i].second, 1);
    }

    int answer = 0;
    for (int i = 0; i < n; i++) {
        answer += la[i] * gb[i];
    }

    cout << answer << "\n";
}

/*
NOTES:
we need gb[i] = number of elements before a[i] and > a[i]
we need la[i] = number of elements after a[i] and < a[i]
answer for is sum of gb[i] + la[i] over i = 1 .. n
*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}