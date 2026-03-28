// D. Vika and Segments
// URL: https://codeforces.com/problemset/problem/610/D
// Time: 3/28/2026, 9:12:10 PM
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

struct BIT {
    int n;
    vector<int> t;
    BIT(int n) : n(n), t(n + 1, 0) {}
    void update(int i, int val) { for (i++; i <= n; i += i & -i) t[i] += val; }
    int query(int i) { int s = 0; for (i++; i > 0; i -= i & -i) s += t[i]; return s; }
    int query(int l, int r) { return l > r ? 0 : query(r) - (l ? query(l - 1) : 0); }
};

void solve() {
    int n; cin >> n;

    // {key, lo, hi}  —  horiz: key=y, lo=x1, hi=x2
    //                    vert:  key=x, lo=y1, hi=y2
    vector<array<int, 3>> horiz, vert;

    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);
        if (y1 == y2) horiz.push_back({y1, x1, x2});
        else          vert.push_back({x1, y1, y2});
    }

    // Merge collinear overlapping / touching segments so no cell is double-counted
    auto merge_segs = [](vector<array<int, 3>>& segs) {
        sort(all(segs));
        vector<array<int, 3>> res;
        for (auto& s : segs) {
            if (!res.empty() && res.back()[0] == s[0] && res.back()[2] >= s[1])
                res.back()[2] = max(res.back()[2], s[2]);
            else
                res.push_back(s);
        }
        return res;
    };

    horiz = merge_segs(horiz);
    vert  = merge_segs(vert);

    // Total length = sum of all merged segment lengths
    int total = 0;
    for (auto& h : horiz) total += h[2] - h[1] + 1;
    for (auto& v : vert)  total += v[2] - v[1] + 1;

    // Answer = total - intersections  (cells counted in both a horiz and a vert segment)

    // Compress x-coordinates used in events
    vector<int> xs;
    for (auto& h : horiz) { xs.push_back(h[1]); xs.push_back(h[2]); }
    for (auto& v : vert)  xs.push_back(v[0]);
    sort(all(xs)); xs.erase(unique(all(xs)), xs.end());
    int M = (int)xs.size();

    // Map actual x → compressed index (exact match only)
    auto compress = [&](int x) {
        return (int)(lower_bound(all(xs), x) - xs.begin());
    };
    // Range [x1,x2] → compressed [l, r]  (all compressed indices whose value is in [x1,x2])
    auto crange = [&](int x1, int x2) -> pair<int,int> {
        int l = (int)(lower_bound(all(xs), x1) - xs.begin());
        int r = (int)(upper_bound(all(xs), x2) - xs.begin()) - 1;
        return {l, r};
    };

    // Sweep line events — type determines processing order at the same y:
    //   0 = open  (top of a vertical segment)
    //   1 = query (horizontal segment)
    //   2 = close (bottom of a vertical segment)
    //
    // At equal y: opens first → query sees all verticals that touch this y from above
    //             query before close → query sees verticals that end exactly at this y
    struct Event { int y, type, a, b; };
    vector<Event> events;

    for (auto& v : vert) {
        events.push_back({v[2], 0, v[0], 0}); // open  at top y
        events.push_back({v[1], 2, v[0], 0}); // close at bottom y
    }
    for (auto& h : horiz) {
        events.push_back({h[0], 1, h[1], h[2]}); // query over x-range
    }

    // Sort top-to-bottom (decreasing y), tie-break by type
    sort(events.begin(), events.end(), [](const Event& a, const Event& b) {
        return a.y != b.y ? a.y > b.y : a.type < b.type;
    });

    BIT bit(M);
    int intersections = 0;

    for (auto& e : events) {
        if      (e.type == 0) bit.update(compress(e.a), +1);
        else if (e.type == 2) bit.update(compress(e.a), -1);
        else {
            auto [l, r] = crange(e.a, e.b);
            if (l <= r) intersections += bit.query(l, r);
        }
    }

    cout << total - intersections << "\n";
}

/*
  Approach:
  1. Separate segments into horizontal {y, x1, x2} and vertical {x, y1, y2}.
  2. Merge collinear overlapping/touching segments so each cell belongs to at most
     one horizontal and at most one vertical merged segment.
  3. answer = sum_of_lengths - #intersections
     An "intersection" = a cell belonging to BOTH a merged horiz and a merged vert.
  4. Count intersections with a top-to-bottom sweep line + BIT on compressed x:
       - vertical top   → point-update +1
       - horizontal     → range-query  [x1, x2]
       - vertical bottom→ point-update -1
*/

/*

*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) solve();
}