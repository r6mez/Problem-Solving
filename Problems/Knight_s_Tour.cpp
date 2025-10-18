/*
    One day, I'm gonna grow wings
*/
// Knight's Tour
// URL: https://cses.fi/problemset/task/1689
// Time: 10/11/2025, 3:33:18 PM
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

int dx[] = { 1, 2, -1, -2, -1,  1, -2,  2 };
int dy[] = { 2, 1, -2, -1,  2, -2,  1, -1 };
int n = 8;

vector<vi> board(n, vi(n, -1));

bool valid(int i, int j) {
    return i >= 0 && j >= 0 && i < n && j < n && board[i][j] == -1;
}

int check_count(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        int vx = x + dx[i];
        int vy = y + dy[i];
        if (valid(vx, vy)) cnt++;
    }
    return cnt;
}

bool calc(int i, int j, int cnt) {
    board[i][j] = cnt;
    if (cnt == n * n) return true;

    for (int k = 0; k < 8; k++) {
        int newI = i + dx[k], newJ = j + dy[k];
        if (valid(newI, newJ) == false) continue;
        if (calc(newI, newJ, cnt + 1)) return true;
    }

    board[i][j] = -1;
    return false;
}

void solve() {
    int x, y;
    cin >> x >> y;
    calc(x - 1, y - 1, 1);
    for (vi row : board) {
        cout << row << "\n";
    }
}

/*

*/

signed main() {
    // UseFile();
    // FastIO();
    int t = 1;
    // cin >> t;
    while (t--) solve();
}