// B. Range Prime Query
// URL: https://codeforces.com/group/Rilx5irOux/contest/603453/problem/B
// Time: 5/19/2026, 6:14:46 PM
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

    vi primes(n);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (!isPrime[i]) continue;
        primes.push_back(i); 
        for (int j = i * i; j <= n; j += i){
            isPrime[j] = false;
        }
    }
    
    int t; cin >> t;
    while (t--) {

    }
}

/*

*/

signed main() {
    // UseFile();
    FastIO();
    solve();
}