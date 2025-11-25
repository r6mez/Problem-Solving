/*
    One day, I'm gonna grow wings
*/
// C. Dungeon
// URL: https://codeforces.com/contest/2164/problem/C
// Time: 11/6/2025, 9:08:49 PM
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
    vi a(n), b(m); cin >> a >> b;
    vector<pair<int,int>> good;
    deque<int> bad;
    priority_queue<int, vi ,greater<int>> pq;
    for (int i = 0; i < n; i++) {
        pq.push(a[i]);
    }

    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        if (x) {
            good.emplace_back(b[i], x);
        } else bad.push_back(b[i]);
    }

    sort(all(good));
    sort(all(bad));
    
    int ans = 0;
    for (int i = 0; i < good.size(); i++) {
        while (!pq.empty() && pq.top() < good[i].first) {
            if (!bad.empty() && pq.top() >= bad.front()) {
                ans++;
                bad.pop_front();
            }
            pq.pop();
        }

        if (!pq.empty()) {
            ans++;
            auto cur = max(pq.top(), good[i].second);
            pq.pop();
            pq.push(cur);
        }
    }

    while (!pq.empty() ) {
        if (!bad.empty() && pq.top() >= bad.front()) {
            ans++;
            bad.pop_front();
        }
        pq.pop();
    }

    cout << ans << endl;
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