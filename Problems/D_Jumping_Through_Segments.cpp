// D. Jumping Through Segments
// URL: https://codeforces.com/contest/1907/problem/D
// Time: 12/10/2025, 4:54:00 PM
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

struct seg {
    int l, r;
};

void solve() {
    int n; cin >> n;
    vector<seg> segs(n);
    for (int i = 0; i < n; i++){
        cin >> segs[i].l >> segs[i].r;
    }
    
    function<bool(int)> can = [&](int k) -> bool {
        int x = 0;
        int ll = 0, rr = 0;
        for(auto [l, r] : segs){
            ll = max(ll - k, l);
            rr = min(rr + k, r);
            if(ll > rr) return false;
        }
        return true;
    };

    int l = -1, r = 2e9;
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