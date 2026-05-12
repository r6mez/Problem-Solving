// M. Reader despite the pressures
// URL: https://codeforces.com/group/Rilx5irOux/contest/636870/problem/M
// Time: 5/12/2026, 3:55:30 PM
#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <functional>
#include <set>
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
    int n, d, h; cin >> n >> d >> h;
    vi p(n); cin >> p;

    sort(all(p));

    function<bool(int)> can = [&](int v) -> bool {
        int limit = h * v;
        if(p[n-1] > limit) return false;

        int l = 0, h = n - 1, days = 0;
        while(l <= h) {
            days++;
            if(l == h) break;

            if(p[l] + p[h] <= limit) {
                l++; h--;
            } else {
                h--;
            }
        }

        return days <= d;
    };

    int l = 0, r = 1e10;
    while(l + 1 < r){
        int mid = (l + r)/2;
        if(can(mid)) r = mid;
        else l = mid;
    }

    if(!can(r)) cout << "-1\n";
    else cout << r << "\n";
}

/*
n chapters
chapter i has pi pages
d days to finish -> read at most 2 chapters
h miniutes per day
reading speed is v (unknown)

l + r <= h * v
*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}