// F2. Sheldon's Parisian Challenge: The Locks Evolve
// URL: https://nucpa.contest.codeforces.com/group/jiO369yEKE/contest/671480/problem/F2
// Time: 2/14/2026, 10:23:15 PM
#include <bits/stdc++.h>
using namespace std;
#define int         long long
#define vi          vector<int>
#define pii         pair<int, int>
#define all(v)      v.begin(), v.end()
#define finish(s)   { cout << s << "\n"; return; }
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { cin.tie(nullptr)->sync_with_stdio(false); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007, INF = 2e18;

int NMAX = 1e6;
vi spf(NMAX + 1, 1);

int pwmod(int a, int b, int m) {
    a %= m;
    int result = 1;
    while (b > 0) {
        if (b & 1) result = (result * a) % m;
        a = (a * a) % m;
        b /= 2;
    }
    return result;
}

int modinv(int n) {
    return pwmod(n, MOD - 2, MOD);
}

const int inf = 1e9;

struct Node {
    Node* l = 0, * r = 0;
    int lo, hi;
    int prod = 1, mn_spf = 1;
    int la = 1, lb = 0;

    Node(int lo, int hi) : lo(lo), hi(hi) {}

    Node(vector<int>& v, int lo, int hi) : lo(lo), hi(hi) {
        if (lo + 1 < hi) {
            int mid = lo + (hi - lo) / 2;
            l = new Node(v, lo, mid);
            r = new Node(v, mid, hi);
            prod = (l->prod * r->prod) % MOD;
            mn_spf = min(l->mn_spf, r->mn_spf);
        }
        else {
            prod = mn_spf = v[lo];
        }
    }

    void push() {
        if (!l) {
            int mid = lo + (hi - lo) / 2;
            l = new Node(lo, mid);
            r = new Node(mid, hi);
        }
        if (la != 1 || lb != 0) {
            l->apply(la, lb);
            r->apply(la, lb);
            la = 1;
            lb = 0;
        }
    }

    void apply(int a, int b) {
        la = la * a;
        lb = lb * a + b;
    }

    void update(int L, int R, int a, int b) {
        if (R <= lo || hi <= L)
            return;
        if (L <= lo && hi <= R) {
            apply(a, b);
        }
        else {
            push();
            l->update(L, R, a, b);
            r->update(L, R, a, b);
            prod = (l->prod * r->prod) % MOD;
            mn_spf = min(l->mn_spf, r->mn_spf);
        }
    }

    int query_spf(int L, int R) {
        if (R <= lo || hi <= L)
            return -inf;
        if (L <= lo && hi <= R)
            return mn_spf;
        push();
        return min(l->query_spf(L, R), r->query_spf(L, R));
    }

    int query_prod(int L, int R) {
        if (R <= lo || hi <= L)
            return -inf;
        if (L <= lo && hi <= R)
            return prod;
        push();
        return (l->query_prod(L, R) * r->query_prod(L, R)) % MOD;
    }

    void set(int L, int R, int x) { update(L, R, 0, x); }
    void add(int L, int R, int x) { update(L, R, 1, x); }
    void mult(int L, int R, int x) { update(L, R, x, 0); }
};


void solve() {
    int n, q; cin >> n >> q;
    vi a(n);
    vi pref(n + 1, 1);

        for (int i = 0; i < n; i++) {
        cin >> a[i];
        pref[i + 1] = (pref[i] * a[i]) % MOD;
        st.update(i, spf[a[i]]);
    }


    while (q--) {
        int l, r; cin >> l >> r;
        int prod = (pref[r] * modinv(pref[l - 1])) % MOD;
        int minPrimeFactor = st.query(l - 1, r);

        cout << (prod * modinv(minPrimeFactor)) % MOD << "\n";
    }
}

/*

*/

signed main() {
    spf[0] = 0; spf[1] = 1;
    for (int i = 2; i <= NMAX; ++i)
        if (spf[i] == 1)
            for (int j = i; j <= NMAX; j += i)
                if (spf[j] == 1)
                    spf[j] = i;

    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}