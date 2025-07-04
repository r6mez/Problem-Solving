/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// Printing some primes
// URL: https://www.spoj.com/problems/TDPRIMES/
// Time: 7/3/2025, 4:48:38 PM
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

void seive(int n){
    int cnt = 0;
    vector<bool> isPrime(n+1, true);
    for (int i = 2; i <= n; i++) {
        if (!isPrime[i]) continue;
        cnt++;
        if(cnt % 100 == 1) cout << i << "\n";

        for (int j = i * i; j <= n; j += i){
            isPrime[j] = false;
        }
    }
}

void Ramez() {
    seive(1e8);
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