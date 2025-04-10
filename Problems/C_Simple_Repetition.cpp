/*
    I thought I could bring an end to the world's suffering,
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// C. Simple Repetition
// URL: https://codeforces.com/contest/2093/problem/C
// Time: 4/8/2025, 4:44:23 PM
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

bool isPrime(int n) {
    if (n == 2) return true;
    if (n == 1 || n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

void Ramez() {
    int n, k; cin >> n >> k;
    
    if(k == 1){
        if(isPrime(n)) cout << "YES\n";
        else cout << "NO\n";
    } else {
        if(n > 1){
            cout << "NO\n";
        } else {
            if(k == 2) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
 
/*
NOTES:
333
*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}