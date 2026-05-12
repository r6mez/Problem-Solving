// L. Final Calibration
// URL: https://codeforces.com/group/Rilx5irOux/contest/636870/problem/L
// Time: 5/12/2026, 4:51:47 PM
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

int mergeCount(vector<int>& a, int l, int r) {
    if (r - l <= 1) return 0;
    int m = (l + r) / 2;
    int inv = mergeCount(a, l, m) + mergeCount(a, m, r);

    vector<int> tmp;
    int i = l, j = m;
    while (i < m && j < r) {
        if (a[i] <= a[j]) {
            tmp.push_back(a[i++]);
        } else {
            inv += (m - i);
            tmp.push_back(a[j++]);
        }
    }
    while (i < m) tmp.push_back(a[i++]);
    while (j < r) tmp.push_back(a[j++]);
    copy(all(tmp), a.begin() + l);
    return inv;
}

void solve() {
    int n; cin >> n;
    vi a(n); cin >> a;
    int count = mergeCount(a, 0, n);
    if(count % 2 == 0) cout << count << "\n";
    else cout << "-1\n";
}

/*
4 3 2 1 5 
moving 1 to its position -> 3 swap
1 4 3 2 5 
moving 4 to its position -> 2 swap
1 3 2 4 5 
moving 2 to its position -> 1 swap
1 2 3 4 5

sum of swaps = 6 even = stable

1 3 2 
moving 2 to its position -> 1 swap
1 2 3

sum of swap = 1 odd -> unstable
*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}