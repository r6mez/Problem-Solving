// E. Can You Guess the Game?
// URL: https://codeforces.com/group/Rilx5irOux/contest/678837/problem/E
// Time: 4/18/2026, 1:57:42 PM
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

int n;
int x, y;

void solve() {
    long long n, y, w;
    cin >> n >> y >> w;

    if (((y - w) % 3 + 3) % 3 != 0) finish(-1);

    long long d  = 3*n - y - w;
    long long wy = (2*y + w - 3*n) / 3;
    long long ww = (2*w + y - 3*n) / 3;

    if (d < 0 || wy < 0 || ww < 0) finish(-1);

    string h;
    h.reserve(2*n);
    h.append(d,  'D'); h.append(ww, 'L'); h.append(wy, 'W'); // Yooussef
    h.append(d,  'D'); h.append(ww, 'W'); h.append(wy, 'L'); // Wageeh

    cout << h;
}

/*

scores X Y

Order:
D D
L W
W L

4 7
D D 1 1
L W 1 4
L W 1 7
W L 4 7

there's a prioity for D D
we can do min(X % 3, Y % 3) D D
if X % 3 != Y % 3 output = -1
after that we do as much as  L W then W L as X/3 and Y/3
that's the minimum we can do
the maximium is take 3 from both sides and convert it to 3 D D matches

5
7 4
D D 1 1
D D 2 2
D D 3 3
D D 4 4
W L 7 4
*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) solve();
}