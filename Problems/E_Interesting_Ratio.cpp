/*
    I thought I could bring an end to the world's suffering,
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// E. Interesting Ratio
// URL: https://codeforces.com/contest/2091/problem/E
// Time: 3/25/2025, 5:49:25 PM
#include <bits/stdc++.h>
using namespace std;
#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007;

vi linearSieve(int n) {
    vector<bool> isPr(n + 1, 1);
    vi primes;
    isPr[0] = isPr[1] = 0;
    for (int i = 2; i <= n; i++) {
        if (isPr[i]) primes.push_back(i);
        for (int p : primes) {
            if (i * p >= n + 1) break;
            isPr[i * p] = 0;
            if (i % p == 0) break;
        }
    }
    return primes;
}

void Ramez() {
    int t; cin >> t;
    vi primes = linearSieve(1e7 + 5);
    while(t--){
        int n; cin >> n;
        int ans = 0;
        for (int i = 0; i < primes.size() && primes[i] <= n; i++){
            ans += n / primes[i];
        }
        cout << ans << "\n";
    }
}

/*
NOTES:

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}