/*
    One day, I'm gonna grow wings
*/
// D. For the Champion
// URL: https://codeforces.com/contest/2136/problem/D
// Time: 8/28/2025, 6:47:19 PM
#include <bits/stdc++.h>
using namespace std;
#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { cin.tie(nullptr)->sync_with_stdio(false); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007;

int ask(char dir, int dis) {
    cout << "? " << dir << " " << dis << endl;
    cout.flush();
    int response; cin >> response;
    if (response == -1) exit(0);
    return response;
}

void answer(int x, int y) {
    cout << "! " << x << " " << y << endl;
    cout.flush();
}

void solve() {
    int n; cin >> n;
    vector<pii> points(n);
    for (auto& p : points) cin >> p.first >> p.second;

    int d1 = ask('U', 0);
    int dU = ask('U', d1); ask('D', d1);
    int dR = ask('R', d1); ask('L', d1);
    int dD = ask('D', d1); ask('U', d1);
    int dL = ask('L', d1); ask('R', d1);

    vector<pii> goal;
    for (auto& [x, y] : points) {
        //UR
        if (dD % 2 == 0 && dL % 2 == 0) {
            int dx = dD / 2; int dy = dL / 2;
            if (dx + dy == d1) goal.push_back({ x + dx, y + dy });
        }

        // UL
        if (dD % 2 == 0 && dR % 2 == 0) {
            int dx = dD / 2; int dy = dR / 2;
            if (dx + dy == d1) goal.push_back({ x - dx, y + dy });
        }

        // DL
        if (dU % 2 == 0 && dR % 2 == 0) {
            int dx = dU / 2; int dy = dR / 2;
            if (dx + dy == d1) goal.push_back({ x - dx, y - dy });
        }

        // DR
        if (dU % 2 == 0 && dL % 2 == 0) {
            int dx = dU / 2; int dy = dL / 2;
            if (dx + dy == d1) goal.push_back({ x + dx, y - dy });
        }
    }

    auto check = [&](int qx, int qy) {
        int d = LLONG_MAX;
        for (auto& [x, y] : points) d = min(abs(qx - x) + abs(qy - y), d);
        return d;
    };

    vector<pii> valid;
    for (auto& [cx, cy] : goal) {
        if (check(cx, cy) == d1 &&
            check(cx, cy + d1) == dU &&
            check(cx + d1, cy) == dR &&
            check(cx, cy - d1) == dD &&
            check(cx - d1, cy) == dL) {
            valid.push_back({ cx, cy });
        }
    }

    if (valid.size() == 1) {
        answer(valid[0].first, valid[0].second);
        return;
    } 

    int test = 1e9, final = ask('R', test);
    for (auto& [x, y] : valid) {
        if (check(x + test, y) == final) {
            answer(x, y);
            return;
        }
    }
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