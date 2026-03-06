// F1. Sheldon's Parisian Challenge
// URL: https://nucpa.contest.codeforces.com/group/jiO369yEKE/contest/671480/problem/F1
// Time: 2/14/2026, 10:03:54 PM
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

int modinv(int n){
    return pwmod(n, MOD - 2, MOD);
}

struct Tree {
    typedef int T;
    static constexpr T unit = INT_MAX;
    T f(T a, T b) { return min(a, b); } // (any associative fn )
    vector<T> s; int n;
    Tree(int n = 0, T def = unit) : s(2 * n, def), n(n) {}
    void update(int pos, T val) {
        for (s[pos += n] = val; pos /= 2;)
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }
    T query(int b, int e) { // query [ b , e)
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, s[b++]);
            if (e % 2) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};

void solve() {
    int n, q; cin >> n >> q;
    vi a(n);
    vi pref(n + 1, 1);

    Tree st(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        pref[i + 1] = (pref[i] * a[i]) % MOD;
        st.update(i, spf[a[i]]);
    }


    while(q--){
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