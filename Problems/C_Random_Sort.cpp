/*
    I was alone in an empty universe.
    A universe too small and at the same time... too infinite.
*/
// C. Random Sort
// URL: https://codeforces.com/group/o09Gu2FpOx/contest/542182/problem/C
// Time: 7/23/2025, 5:09:58 PM
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
const int MOD = 7901;

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
        for (int i = 2; i <= n; ++i) {
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

    int nPrLinear(int n, int r) {
        int answer = 1;
        for (int i = n - r + 1; i <= n; i++) {
            answer = multiply(answer, i);
        }
        return answer;
    }

    int nCrLinear(int n, int r) {
        int answer = 1;
        for (int i = r + 1; i <= n; i++) {
            answer = multiply(answer, i);
            answer = divide(answer, i - r);
        }
        return answer;
    }
};
using namespace combinatorics;


void Ramez() {
    int n; cin >> n;
    map<int, int> freq;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        freq[x]++;
    }

    int cnt = 1;
    for(auto [x, f] : freq){
        cnt = (cnt * fact[f]) % MOD;
    }

    cout << cnt << "\n";
}

/*
NOTES:

*/

int32_t main() {
    init(1e6);
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}