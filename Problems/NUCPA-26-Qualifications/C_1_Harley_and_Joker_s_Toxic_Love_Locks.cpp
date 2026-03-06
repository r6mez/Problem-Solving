// C1. Harley and Joker's Toxic Love Locks
// URL: https://nucpa.contest.codeforces.com/group/jiO369yEKE/contest/671480/problem/C1
// Time: 2/14/2026, 9:20:11 PM
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
    vi a(n), b(n); cin >> a >> b;

    vi seen(61, -1);
    vi minStart(n);
    int ops = 0;
    for (int i = 0; i < n; i++){
        minStart[i] = i + 1;
        for (int bit = 0; bit < 60; bit++){
            if((a[i] >> bit) & 1){
                seen[bit] = i;
            }

            if((b[i] >> bit) & 1){
                if(seen[bit] == -1) finish(-1);
                minStart[i] = min(minStart[i], seen[bit] + 1);
            }
        }
    }

    int currMin = n + 1;
    for(int i = n - 1; i >= 0; i--) {
        currMin = min(currMin, minStart[i]);
        if(i >= currMin) ops++;
    }
    
    cout << ops << "\n";
}

/*

*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}