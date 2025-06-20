/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// D. Triangle Coloring
// URL: https://codeforces.com/problemset/problem/1795/D
// Time: 6/19/2025, 1:37:37 PM
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
const int MOD = 998244353;

int add(int a, int b) { return ((a % MOD) + (b % MOD)) % MOD; }
int mul(int a, int b) { return ((a % MOD) * (b % MOD)) % MOD; }
int sub(int a, int b) { return ((((a % MOD) - (b % MOD)) % MOD) + MOD) % MOD; }

int pwmod(int b, int p) {
    if (!p) return 1LL;
    int ret = pwmod(b, p >> 1LL);
    ret = mul(ret, ret);
    if (p & 1LL)
        ret = mul(ret, b);
    return ret;
}

const int SizeMax = 1e6 + 2;

vi fac(0), inv(0);

void buildFacAndInvFac() {
    fac.resize(SizeMax);
    inv.resize(SizeMax);
    fac[0] = 1;
    for (int i = 1; i < SizeMax; ++i) {
        fac[i] = mul(fac[i - 1], i);
    }
    inv[0] = 1;
    for (int i = 1; i < SizeMax; ++i) {
        inv[i] = pwmod(fac[i], MOD - 2);
    }
}

int nCr2(int n, int r) {
    if (r > n) return 0;
    return mul(mul(fac[n], inv[n - r]), inv[r]);
}

void Ramez() {
    int n; cin >> n;
    vi a(n); cin >> a;

    int cnt = 1;
    for (int i = 0; i < n - 2; i += 3) {
        int x = a[i], y = a[i + 1], z = a[i + 2];
        int sum1 = x + y;
        int sum2 = x + z;
        int sum3 = y + z;
        int mx = max({ sum1, sum2, sum3 });
        int ways = 0;
        if (sum1 == mx) ++ways;
        if (sum2 == mx) ++ways;
        if (sum3 == mx) ++ways;
        cnt = mul(cnt, ways);
    }


    buildFacAndInvFac();
    cnt = mul(cnt, nCr2(n / 3, n / 6));

    cout << cnt << "\n";
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