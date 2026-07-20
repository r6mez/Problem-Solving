// M. Doors
// URL: https://codeforces.com/group/zZYq310uLQ/contest/615216/problem/M
// Time: 7/8/2026, 7:37:38 PM
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
    int n, x; cin >> n >> x;
    vi c(n), a(n);
    cin >> c >> a;

    function<bool(int)> can = [&](int k) -> bool {
        int pocket = x, ops = 0;
        priority_queue<int> pq; 
        for(int i = 0; i < n; i++){
            pq.push(c[i]);
            if (pocket >= c[i]) {
                pocket -= c[i];
                pocket += a[i];
                continue;
            }
            
            while(pocket < c[i] && !pq.empty() && ops < k){
                ops++;
                pocket += pq.top(); pq.pop();
            }

            if (pocket < c[i] || ops > k) {
                return false;
            }

            pocket -= c[i];
            pocket += a[i];
        }

        return true;
    };
    
    int l = -1, r = n + 1;
    while(l + 1 < r){
        int mid = (l + r)/2;
        if(can(mid)) r = mid;
        else l = mid;
    }

    cout << r << "\n";
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