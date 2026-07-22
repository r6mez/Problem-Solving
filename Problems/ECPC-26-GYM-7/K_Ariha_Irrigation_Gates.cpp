// K. Ariha Irrigation Gates
// URL: https://codeforces.com/group/zZYq310uLQ/contest/703989/problem/K
// Time: 7/22/2026, 2:32:54 PM
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
    int n; cin >> n;
    vi a(n); cin >> a;
    if (n == 1 && a[0] == 0) finish(-1);

    vi b(n + 1);
    bool isDiff = false;
    for (int i = 1; i < n; i++) {
        if(i % 2 == 1) {
            if (a[i] == 1 && isDiff == false) {
                b[i + 1] = 1;
                isDiff = true;
                continue;
            }

            if (a[i] == 0) {
                isDiff = true;
            }
            b[i] = 1;
        } else {
            if(a[i] == 1) isDiff = true;
        }
    }
    
    int sum = 0;
    bool wrong = false;
    for (int i = 0; i < n; i++) {
        sum += b[i];
        if(sum > (i + 1) / 2) wrong = true;
        cout << b[i] << " ";
    } cout << "\n";

    // if (a == b) wrong = true;
    // if (wrong) cout << "WRONG\n";
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