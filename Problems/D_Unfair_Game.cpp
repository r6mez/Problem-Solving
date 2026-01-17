// D. Unfair Game
// URL: https://codeforces.com/contest/2184/problem/D
// Time: 1/13/2026, 12:38:17 AM
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

void solve() {
    init(31);

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;

        int copyN = n;

        int bitsCount = 0;
        while (copyN) {
            bitsCount++;
            copyN /= 2;
        }

        // checking invalid cases

        int answer = bitsCount > k ? 1 : 0; // for n itself

        int b = bitsCount - 1;
        for (int x = 0; x <= b; x++) { // number of ones
            for (int MSB = x; MSB <= b; MSB++) { // position of MSB
                if ((x * 2 - 1) + (MSB - x) <= k) continue;
                answer += nCr(MSB - 1, x - 1); // choosing x - 1 ones from remaining MSB - 1 bits
            }
        }

        cout << answer << "\n";
    }
}

/*
bob choses a number from 1 to n (n is power of 2)
alice can half the number (if even) or subtract 1
if the number become 0 alice wins
the game have k moves

given n and k
calculate the number of initial numbers from 1 to n
such that Alice, playing optimally, cannot win in no more than k moves.

n, k = 1e9

BEST STRATEGY FOR ALICE:
for each number alice will half if it's even and subtract 1 if it's odd until it becomes 0

x, steps
1  1
2  2
3  3
4  3
5  4
6  4
7  5
8  4
9  5
10 5
11 6
12 5
13 6
14 6
15 7
16 5
17 6
18 6
19 7
20 6

1011010
every zero can be removed in one step (half)
every one can be removed in two steps (subtract 1 + half)
since n is multiple of 2
then n - 1 is 11111111...

for every number of bits b from 1 to MSB(n)
we need to find x, such that 2 * x + (b - x) > k
what's the number of ways to choose x ones from b bits
that's nCr because order doesn't matter


111111
overlabbing cases
  0001
   001
    01
     1

b = MSB - 1
x * 2 + (b - x) > k
2 * x - x > k - b
x > k - b
x = [k - b + 1, b]

actually the MSB requires only 1 step to remove
so with x ones and b bits
it requires (x * 2 - 1) + (b - x) steps

the problem now is that choosing x ones from b bits results invlaid number of steps
because the ones may be placed at the start only and all leading zeros is useless
so we want to choose x ones from b bits such that the last bit at the left is 1
so we need to iterate over all possible places to put that MSB and caclulate
the number of ways to choose x - 1 ones from the remaining b - pos bits
*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) solve();
}