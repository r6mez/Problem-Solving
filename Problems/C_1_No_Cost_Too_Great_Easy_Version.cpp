/*
    One day, I'm gonna grow wings
*/
// C1. No Cost Too Great (Easy Version)
// URL: https://codeforces.com/contest/2154/problem/C1
// Time: 10/19/2025, 9:43:48 PM
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


const int MAXV = 200000 + 20;
int spf[MAXV];
int cnt[MAXV];
void buildSpf() {
    for (int i = 0;i < MAXV;i++) spf[i] = i;
    for (int i = 2;i * i < MAXV;i++) if (spf[i] == i)
        for (int j = i * i;j < MAXV;j += i) if (spf[j] == j) spf[j] = i;
}

vector<int> primesOf(int x) {
    vector<int> r;
    while (x > 1) {
        int p = spf[x];
        r.push_back(p);
        while (x % p == 0) x /= p;
    }
    return r;
}

void solve() {
    int n; if (!(cin >> n)) return;
    vector<int>a(n), b(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    for (int i = 0;i < n;i++) cin >> b[i];

    vector<int> seen;
    for (int i = 0;i < n;i++) {
        auto ps = primesOf(a[i]);
        for (int p : ps) {
            if (cnt[p] == 0) seen.push_back(p);
            cnt[p]++;
            if (cnt[p] >= 2) {
                cout << 0 << "\n";
                for (int q : seen) cnt[q] = 0;
                return;
            }
        }
    }

    for (int i = 0;i < n;i++) {
        auto ps = primesOf(a[i] + 1);
        for (int p : ps) if (cnt[p] > 0) {
            cout << 1 << "\n";
            for (int q : seen) cnt[q] = 0;
            return;
        }
    }

    cout << 2 << "\n";
    for (int q : seen) cnt[q] = 0;
}

/*
if any two duplicates and not equal to 1 answer is 0
if there's two evens answer is 0
if there's one even answer is 1
otherwise it's 2
*/

signed main() {
    // UseFile();
    FastIO();
    buildSpf();
    int t = 1;
    cin >> t;
    while (t--) solve();
}