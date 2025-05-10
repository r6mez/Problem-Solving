/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// B. Integers Have Friends
// URL: https://codeforces.com/problemset/problem/1548/B
// Time: 5/10/2025, 4:22:25 PM
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

struct SparceTable {
    int n;
    vi a;
    vector<vi> t;
    vi log;

    SparceTable(int n, vi a) : n(n), a(a) {
        log = vi(n + 1);
        build();
    }

    int merge(int a, int b) {
        return gcd(a, b); // You can customize this
    }

    void build() {
        log[1] = 0;
        for (int i = 2; i <= n; i++){
            log[i] = log[i/2] + 1;
        }

        t = vector<vi>(n, vi(log[n] + 1));

        for (int i = 0; i < n; i++) {
            t[i][0] = a[i];
        }

        for (int pw = 1; (1 << pw) <= n; pw++) {
            for (int i = 0; i + (1 << pw) <= n; i++) {
                t[i][pw] = merge(t[i][pw - 1], t[i + (1 << (pw - 1))][pw - 1]);
            }
        }
    }

    int query(int l, int r){
        int pw = log[r - l + 1];
        return merge(t[l][pw], t[r - (1 << pw) + 1][pw]);
    }
};

void Ramez() {
    int n; cin >> n;
    vi a(n); cin >> a;

    if (n == 1) {
        cout << 1 << "\n";
        return;
    }

    vi diff(n - 1);
    for (int i = 0; i < n - 1; i++) {
        diff[i] = abs(a[i+1] - a[i]);
    }

    SparceTable st(n - 1, diff);

    function<bool(int, int)> can = [&](int l, int r){
        return st.query(l, r) >= 2;
    };

    int mxsz = -1;
    for (int i = 0; i < n - 1; i++){
        int l = i - 1, r = n - 1;
        while(l + 1 < r){
            int mid = (l + r)/2;
            if(can(i, mid)) l = mid;
            else r = mid;
        }

        mxsz = max(mxsz, l - i + 2);
        // cout << i << " " << i << " " << l - i + 1 << "\n";
    }
    
    cout << mxsz << "\n";
}

/*
NOTES:

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}