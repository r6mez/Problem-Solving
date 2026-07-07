// N. Matrix Distances
// URL: https://codeforces.com/group/zZYq310uLQ/contest/701118/problem/N
// Time: 7/5/2026, 12:42:31 AM
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
    unordered_map<int, vi> xs, ys;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int key; cin >> key;
            xs[key].push_back(i);
            ys[key].push_back(j);
        }
    }

    int sum = 0;
    for (auto &[key, arr] : xs) {
        sort(all(arr));
        int end = arr.size() - 1;
        vi prefix(end + 1);
        prefix[0] = arr[0];
        for (int i = 1; i <= end; i++) {
            prefix[i] = prefix[i - 1] + arr[i];
        }
        
        for (int i = 0; i <= end; i++) {
            sum += prefix[end] - prefix[i];
            sum -= arr[i] * (end - i);
            sum += arr[i] * i;
            sum -= i > 0 ? prefix[i - 1] : 0; 
        }
    }

    for (auto &[key, arr] : ys) {
        sort(all(arr));
        int end = arr.size() - 1;
        vi prefix(end + 1);
        prefix[0] = arr[0];
        for (int i = 1; i <= end; i++) {
            prefix[i] = prefix[i - 1] + arr[i];
        }
        
        for (int i = 0; i <= end; i++) {
            sum += prefix[end] - prefix[i];
            sum -= arr[i] * (end - i);
            sum += arr[i] * i;
            sum -= i > 0 ? prefix[i - 1] : 0; 
        }
    }

    cout << sum << "\n";
}

/*

*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) solve();
}