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

struct Fenwick {
    int n;
    vector<int> f;
    Fenwick(int _n) : n(_n), f(n + 1, 0) {}
    void reset() { fill(f.begin(), f.end(), 0); }
    void update(int i, int v) {
        for (; i <= n; i += i & -i)
            f[i] = max(f[i], v);
    }
    int query(int i) const {
        int res = 0;
        for (; i > 0; i -= i & -i)
            res = max(res, f[i]);
        return res;
    }
};


void Ramez() {
    int n; cin >> n;
    vi a(n); cin >> a;

    // compress values
    vi vals = a;
    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());
    int M = vals.size();
    vi idx(n), ridx(n);
    for (int i = 0; i < n; i++) {
        idx[i] = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin() + 1;
        ridx[i] = M - idx[i] + 1;
    }

    vi dpL(n), dpR(n);
    Fenwick fenL(M), fenR(M);

    // compute dpL
    for (int i = 0; i < n; i++) {
        int best = fenL.query(idx[i] - 1);
        dpL[i] = best + 1;
        fenL.update(idx[i], dpL[i]);
    }

    // compute dpR
    fenR.reset();
    for (int i = n - 1; i >= 0; i--) {
        int best = fenR.query(ridx[i] - 1);
        dpR[i] = best + 1;
        fenR.update(ridx[i], dpR[i]);
    }

    int L = *max_element(dpL.begin(), dpL.end());

    vi cnt(L + 1, 0);
    for (int i = 0; i < n; i++) {
        if (dpL[i] + dpR[i] - 1 == L) {
            cnt[dpL[i]]++;
        }
    }

    vi ans(n, L);
    for (int i = 0; i < n; i++) {
        if (dpL[i] + dpR[i] - 1 == L && cnt[dpL[i]] == 1) {
            ans[i] = L - 1;
        }
    }

    cout << ans << "\n";
}


/*

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}
