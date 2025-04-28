/*
    I thought I could bring an end to the world's suffering,
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// D. Array and GCD
// URL: https://codeforces.com/contest/2104/problem/D
// Time: 4/28/2025, 7:58:54 PM
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
    int size = 1e7;
    vi p = linearSieve(size);
    partial_sum(all(p), p.begin());
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vi a(n); cin >> a;
        sort(all(a), greater<int>());
        partial_sum(all(a), a.begin());


        int best = -1;
        for (int k = 0; k < n; k++){
            if(a[k] >= p[k]){
                best = k + 1;
            }
        }
        
        cout << (n - best) << "\n";
    }
}

/*
NOTES:

*/

int32_t main() {
    // UseFile();
    FastIO();
    Ramez();
    return 0;
}