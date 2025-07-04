/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// B. Sherlock and his girlfriend
// URL: https://codeforces.com/contest/776/problem/B
// Time: 7/2/2025, 9:41:52 PM
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


void Ramez() {
    int n; cin >> n; n++;
    int cnt = 0;
    vector<bool> isPrime(n+1, true);
    for (int i = 2; i <= n; i++) {
        if (!isPrime[i]) continue;
        cnt++;
        for (int j = i * i; j <= n; j += i){
            isPrime[j] = false;
        }
    }

    cout << (n <= 3? 1 : 2) << "\n";
    for (int i = 2; i <= n; i++){
        if(isPrime[i]) cout << 1 << " ";
        else cout << 2 << " ";
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