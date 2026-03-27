// B. Array
// URL: https://codeforces.com/contest/2209/problem/B
// Time: 3/27/2026, 11:11:18 PM
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
    int n; cin >> n;
    vi a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vi f1(n + 1), f2(n + 1);

    for(int i = n; i >= 1; i --){
        f1[i] = f2[i] = 0;
        
        for(int j = i + 1; j <= n; j ++)
            f1[i] += (a[i] > a[j]), f2[i] += (a[i] < a[j]);

        f1[i] = max(f1[i],f2[i]);
    }

    for (int i = 1; i <= n; i++) {
        cout << f1[i] << " ";
    } cout << "\n";
}

/*
|aj| >= |ai|
aj - k >= ai - k

aj < ai

*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}