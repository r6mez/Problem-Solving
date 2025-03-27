/*
    I thought I could bring an end to the world's suffering,
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// D. Place of the Olympiad
// URL: https://codeforces.com/contest/2091/problem/D
// Time: 3/25/2025, 5:05:21 PM
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

bool can(int x, int n, int m, int k) {
    if (k == 0) return true;
    return k <= n * ((m / (x + 1)) * x + min(x, (m % (x + 1))));
}


void Ramez() {
    int n, m, k; cin >> n >> m >> k;

    int l = 0, r = m + 1;
    while(l + 1 < r){
        int mid = (l + r) / 2;
        if(can(mid, n, m, k)) r = mid;
        else l = mid;
    }
    cout << r << "\n";
}

/*
NOTES:

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}