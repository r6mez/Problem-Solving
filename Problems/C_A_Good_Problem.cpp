/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// C. A Good Problem
// URL: https://codeforces.com/contest/2119/problem/C
// Time: 7/5/2025, 6:07:01 PM
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

namespace combinatorics {
    vector<int> fact, inv, invFact;

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
    int multiply(int a, int b) { return ((a % MOD) * (b % MOD)) % MOD; }
    int divide(int a, int b) { return multiply(a, inverse(b)); }

    void init(int n) {
        fact.resize(n + 1); inv.resize(n + 1); invFact.resize(n + 1);
        fact[0] = fact[1] = inv[0] = inv[1] = invFact[0] = invFact[1] = 1; 
        for (int i = 2; i <= n; ++i){
            fact[i] = fact[i - 1] * i % MOD;
            inv[i] = MOD - ((MOD / i) * inv[MOD % i]) % MOD;
            invFact[i] = invFact[i - 1] * inv[i] % MOD;
        } 
    }

    int nPr(int n, int r) {
        if (n < 0 || r < 0 || r > n) return 0;
        return fact[n] * invFact[n - r] % MOD;
    }

    int nCr(int n, int r) {
        if (n < 0 || r < 0 || r > n) return 0;
        return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
    }

    int nPrLinear(int n, int r){
        int answer = 1;
        for (int i = n - r + 1; i <= n; i++){
            answer = multiply(answer, i);
        }
        return answer;
    }

    int nCrLinear(int n, int r){
        int answer = 1;
        for (int i = r + 1; i <= n; i++){
            answer = multiply(answer, i);
            answer = divide(answer, i - r);
        }
        return answer;
    }
};
using namespace combinatorics;


long long nextPowerOf2(long long l) {
    int b = 64 - __builtin_clzll(l);   
    return 1LL << b;
}

void Ramez() {
    int n, l, r, k; cin >> n >> l >> r >> k;

    if(n&1){
        cout << l << "\n";
        return;
    }

    if(n == 2){
        cout << "-1\n";
        return;
    }

    int x = nextPowerOf2(l); 

    if(l < x && x <= r){
        if(k <= n - 2) cout << l << "\n";
        else cout << x << "\n";
        return;
    }

    cout << "-1\n";
}

/*
NOTES:
array of size n
l <= a_i <= r
AND all elements == XOR all elements
output a_k

if n odd
    array is [l, l, l, ...]
    a_k = l

if n even 
    we need to numbers l <= x, y <= r with x & y == 0 and x ^ y == 0
    array is [x, x, x ...., y, y, y] dividied by half
    a_k = x if k <= n / 2
    a_k = y if k > n / 2

if n even and n/2 is odd
    then XOR all a != 0
*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}