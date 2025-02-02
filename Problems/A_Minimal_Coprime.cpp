/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all it remained were fields of dreamless solitude.
*/
// A. Minimal Coprime
// URL: https://codeforces.com/contest/2063/problem/A
// Time: 1/23/2025, 2:47:14 PM
#include <bits/stdc++.h>
using namespace std;
#define ll   long long
#define vi   vector<int>
#define vll  vector<ll>
#define pll  pair<ll, ll>
#define all(v)  v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v){ for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v){ for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
int MOD = 1000000007;

vi linearSieve(ll n) {
    vector<bool> isPr(n + 1, 1);
    vi primes = {1};
    isPr[0] = isPr[1] = 0;
    for (ll i = 2; i <= n; i++) {
        if (isPr[i]) primes.push_back(i);
        for (ll p : primes) {
            if (p == 1) continue;
            if (i * p >= n + 1) break;
            isPr[i * p] = 0;
            if (i % p == 0) break;
        }
    }
    return primes;
}

void Ramez() {
    int l, r; cin >> l >> r;
    cout << r - l + (l == r && l == 1) << "\n";
}

/*
NOTES:

*/

int main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}

