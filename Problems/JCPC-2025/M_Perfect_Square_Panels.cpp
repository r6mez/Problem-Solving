// M. Perfect Square Panels
// URL: https://codeforces.com/group/Rilx5irOux/contest/638270/problem/M
// Time: 5/13/2026, 2:29:04 PM
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
    vi h(n); cin >> h;
    vi w(n); cin >> w;
    
    function<bool(int)> can = [&](int s) -> bool {
        int sum = 0, max_sum = 0;
        for(int i = 0; i < n; i++){
            if(h[i] < s) {
                sum = 0;
                continue;
            }

            sum += w[i];
            max_sum = max(max_sum, sum);
        }

        return max_sum >= s;
    };

    int l = 0, r = 1e10;
    while(l + 1 < r){
        int mid = (l + r)/2;
        if(can(mid)) l = mid;
        else r = mid;
    }

    cout << l * l << "\n";
}

/*

*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) solve();
}