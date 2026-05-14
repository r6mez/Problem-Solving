// I. Max Equal Subarray
// URL: https://codeforces.com/group/Rilx5irOux/contest/638270/problem/I
// Time: 5/13/2026, 12:53:16 PM
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
    int curr_sub = 1, mx_sub = 0, zeros = 0, last = 0;
    for(int i = 0; i < n; i++){
        if(i == n - 1){
            mx_sub = max(mx_sub, curr_sub);
            break;
        }

        if(a[i] != 0){
            last = a[i];
            if(a[i] == a[i + 1]) {
                curr_sub++;
            } else if(a[i + 1] == 0){
                zeros++;
                curr_sub++;
            } else {
                mx_sub = max(mx_sub, curr_sub);
                curr_sub = 1;
            }
        } else if(a[i] == 0) {
            if(a[i + 1] == 0){
                curr_sub++;
                zeros++;
            } else {
                if(a[i + 1] == last || last == 0){
                    curr_sub++;
                    zeros = 0;
                } else {
                    mx_sub = max(mx_sub, curr_sub);
                    curr_sub = 1 + zeros;
                    zeros = 0;
                }
            }
        }
    }

    cout << mx_sub << "\n";
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