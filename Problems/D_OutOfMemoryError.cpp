// D. OutOfMemoryError
// URL: https://codeforces.com/contest/2185/problem/D
// Time: 1/19/2026, 12:32:14 PM
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

void solve() {
    int n, m, h; cin >> n >> m >> h;
    vi a(n); cin >> a;

    vector<pii> ops(m);
    for (int i = 0; i < m; i++){
        cin >> ops[i].first >> ops[i].second;
    }
    
    vi b = a;
    vi processed(n, -1);

    int lastReset = -1;
    for (int i = 0; i < m; i++){
        auto [x, c] = ops[i]; x--;

        if (processed[x] != lastReset) {
            b[x] = a[x];
            for (int j = lastReset + 1; j < i; j++){
                auto [lx, lc] = ops[j]; lx--;
                if(lx != x) continue;
                b[lx] += lc;
            }    
            processed[x] = lastReset;
        }
        

        if (b[x] + c > h){
            b[x] = a[x];
            lastReset = i;
        } else {
            b[x] += c;
        }
    }

    b = a;
    for (int i = lastReset + 1; i < m; i++){
        auto [x, c] = ops[i]; x--;
        if (b[x] + c > h){
            b[x] = a[x];
        } else {
            b[x] += c;
        }
    }
    
    cout << b << "\n";
}

/*
if a reset happend, all previous ops are useless
we need to find the last reset
then we can just apply all ops after it


*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}