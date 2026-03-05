// D. Portal
// URL: https://codeforces.com/contest/2200/problem/D
// Time: 3/5/2026, 4:02:36 PM
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
    int n, x, y; cin >> n >> x >> y;
    vi a(n); cin >> a;
    y--;
    
    vi in, out;
    for (int i = 0; i < n; i++) {
        if (x <= i && i <= y) in.push_back(a[i]);
        else out.push_back(a[i]);
    }

    // cout << "in: " << in << "\n";
    // cout << "out: " << out << "\n";

    if (in.size()) {
        int min_start = INT_MAX, min_start_idx = -1;
        for (int i = 0; i < in.size(); i++) {
            if (in[i] < min_start) {
                min_start = in[i];
                min_start_idx = i;
            }
        }
        vi in_copy(in.size());
        for (int i = 0; i < in.size(); i++) {
            in_copy[i] = in[(i + min_start_idx) % in.size()];
        }
        in = in_copy;
    }

    if(in.size() == 0) finish(out);
    if(out.size() == 0) finish(in);

    bool cut = false;
    for (int i = 0; i < out.size(); i++){
        if(!cut && out[i] < in[0]) {
            cout << out[i] << ' ';
        } else if (!cut && out[i] >= in[0]) {
            cut = true;
            cout << in << out[i] << ' ';
        } else {
            cout << out[i] << ' ';
        }
    }

    if (!cut) cout << in;
    cout << "\n";
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