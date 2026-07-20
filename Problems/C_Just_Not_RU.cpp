// C. Just Not RU...
// URL: https://codeforces.com/group/zZYq310uLQ/contest/700325/problem/C
// Time: 7/19/2026, 7:57:16 PM
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
    int n ; cin >> n;
    int count = 0;
    vector<bool> isPrime(n+1, true);
    for (int i = 2; i <= n; i++) {
        if (!isPrime[i]) continue;
        count++; 
        for (int j = i * i; j <= n; j += i){
            isPrime[j] = false;
        }
    }
    cout << count << "\n";
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