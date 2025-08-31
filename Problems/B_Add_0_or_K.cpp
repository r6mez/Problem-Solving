/*
    One day, I'm gonna grow wings
*/
// B. Add 0 or K
// URL: https://codeforces.com/contest/2134/problem/B
// Time: 8/26/2025, 5:48:16 PM
#include <bits/stdc++.h>
using namespace std;
#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { cin.tie(nullptr)->sync_with_stdio(false); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
int MOD = 1000000007;

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

int pwmod(int a, int b) {
    a %= MOD;
    int result = 1;
    while (b > 0) {
        if (b & 1) result = (result * a) % MOD;
        a = (a * a) % MOD;
        b /= 2;
    }
    return result;
}

int inverse(int x) { return pwmod(x, MOD - 2); }

void solve() {
    int n, k; cin >> n >> k;
    vi a(n); cin >> a;

    vi primes = seive(1000);

    int p = -1;
    for(int i : primes){
        if(k % i != 0){
            p = i;
            MOD = i;
            break;
        }
    }

    for (int i = 0; i < n; i++){
        int cnt = ((((-a[i] % p) + p) % p) * inverse(k)) % p;
        a[i] = a[i] + cnt * k;
    }
    
    cout << a << "\n";
}

/*

ai + ci * k (mod p) == 0
(ci * k) (mod p) = -ai (mod p)
ci = (-ai / k) (mod p)
*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}