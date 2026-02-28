// E. Divisive Battle
// URL: https://codeforces.com/contest/2200/problem/E
// Time: 2/28/2026, 8:07:39 PM
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

pair<int, int> getMinMaxPrimeFactors(int n) {
    if(n == 1) 
        return {1, 1};
    int curr_max_pf = INT_MIN;
    int curr_min_pf = INT_MAX;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
                curr_max_pf = max(curr_max_pf, i);
                curr_min_pf = min(curr_min_pf, i);
            }
        }
    }
    if (n > 1) {
        curr_max_pf = max(curr_max_pf, n);
        curr_min_pf = min(curr_min_pf, n);
    }
    return {curr_min_pf, curr_max_pf};
}

void solve() {
    int n; cin >> n;
    vi a(n); cin >> a;

    if(is_sorted(all(a))) finish("Bob");
    
    int pre_mn = INT_MAX, pre_mx = INT_MIN;
    for (int i = 0; i < n; i++) {
        auto [curr_mn, curr_mx] = getMinMaxPrimeFactors(a[i]);

        if (curr_mn != curr_mx || (i != 0 && (curr_mx < pre_mn || curr_mn < pre_mx))) {
            finish("Alice");
        }

        pre_mn = min(pre_mn, curr_mn);
        pre_mx = max(pre_mx, curr_mx);
    }

    finish("Bob");
}

/*
a is not decreasing -> the game ends if you can't make a move, the game ends if the game ends and

A is non-decreasing -> bob wins
otherwise -> alice wins

making a move:
select and element X and replace it with Y, Z such that X = Y * Z and 1 < Y, Z < X

this means if you have a prime number or 1 you can't make a move so bob is trying to replace the elements to make them non decreasing
and alice is doing otherwise

I think the final state of the array is the prime factors of all of it's elements
if smallest prime factor in a[i + 1] < biggest prime factor seen so far (alice wins)
*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}