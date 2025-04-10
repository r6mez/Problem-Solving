/*
    I thought I could bring an end to the world's suffering,
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// D. Skibidi Table
// URL: https://codeforces.com/contest/2093/problem/D
// Time: 4/8/2025, 5:07:34 PM
#include <bits/stdc++.h>
using namespace std;
#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007;

int get(int n, int x, int y) {
    if (n == 1) {
        if (x == 1 && y == 1) return 1;
        if (x == 1 && y == 2) return 4;
        if (x == 2 && y == 1) return 3;
        if (x == 2 && y == 2) return 2;
    }

    int half = 1LL << (n - 1), square = 1LL << (2 * (n - 1));
    if (x <= half && y <= half) return get(n - 1, x, y);
    if (x <= half && y > half) return get(n - 1, x, y - half) + 3 * square;
    if (x > half && y <= half) return get(n - 1, x - half, y) + 2 * square;
    if (x > half && y > half) return get(n - 1, x - half, y - half) + square;
}

pii search(int n, int d) {
    if (n == 1) {
        if (d == 1) return { 1, 1 };
        if (d == 2) return { 2, 2 };
        if (d == 3) return { 2, 1 };
        if (d == 4) return { 1, 2 };
    }

    int half = 1LL << (n - 1), square = 1LL << (2 * (n - 1));

    if (d <= square) {
        auto [x, y] = search(n - 1, d);
        return { x, y };
    }
    if (d > square && d <= 2 * square) {
        auto [x, y] = search(n - 1, d - square);
        return { x + half, y + half };
    }
    if (d > 2 * square && d <= 3 * square) {
        auto [x, y] = search(n - 1, d - 2 * square);
        return { x + half, y };
    }
    if (d > 3 * square && d <= 4 * square) {
        auto [x, y] = search(n - 1, d - 3 * square);
        return { x, y + half };
    }
}

void Ramez() {
    int n, q; cin >> n >> q;
    while (q--) {
        string s; cin >> s;
        if (s == "->") {
            int x, y; cin >> x >> y;
            cout << get(n, x, y) << "\n";
        }
        else {
            int d; cin >> d;
            auto [x, y] = search(n, d);
            cout << x << " " << y << "\n";
        }
    }
}

/*
NOTES:

*/

int32_t main() {
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}
