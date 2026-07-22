// A. Al-Quds Prime Routes
// URL: https://codeforces.com/group/zZYq310uLQ/contest/703989/problem/A
// Time: 7/22/2026, 12:32:30 PM
#include <algorithm>
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

vi seive(int n){
    vi primes;
    vector<bool> isPrime(n+1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (!isPrime[i]) continue;
        primes.push_back(i); 
        for (int j = i * i; j <= n; j += i){
            isPrime[j] = false;
        }
    }
    return primes;
}

vi primes;
vi dp(100, -1);

int calc (int i, int &p) {
    if (i >= p) return 1;

    if(dp[i] != -1) return dp[i];
    
    int sum = 0;
    for(int j = i + 1; j <= p; j++){
        if (primes[j] - primes[i] > 14) {
            break;
        }
        sum += calc(j, p);        
    }
    return dp[i] = sum;
}

void solve() {
    primes = seive(250);
    int n; cin >> n;
    int p = lower_bound(all(primes), n) - primes.begin();
    int answer = calc(0, p);
    cout << answer << "\n";
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