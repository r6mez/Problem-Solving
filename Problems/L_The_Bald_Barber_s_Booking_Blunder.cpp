// L. The Bald Barber's Booking Blunder
// URL: https://codeforces.com/group/Rilx5irOux/contest/643069/problem/L
// Time: 6/2/2026, 9:23:10 PM
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
    int n, m; cin >> n >> m;
    vector<pii> events; // {time, delta}

    for (int i = 0; i < n; i++) {
        int h, mm, dur; char comma;
        cin >> h >> comma >> mm >> dur;
        int s = h * 60 + mm;
        if (s + dur - 1 <= 1440) {
            events.push_back({s, 1});
            events.push_back({s + dur, -1});
        }
    }

    sort(all(events), [](pii a, pii b){
        if (a.first != b.first) return a.first < b.first;
        return a.second < b.second;
    });

    int cur = 0, peak = 0;
    for (auto [time, delta] : events) {
        cur += delta;
        peak = max(peak, cur);
    }

    cout << (peak <= m ? "Yes" : "No") << "\n";
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