/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all that remained were fields of dreamless solitude.
*/
// D. Burning Midnight Oil
// URL: https://codeforces.com/group/3nQaj5GMG5/contest/376466/problem/D
// Time: 3/9/2025, 2:47:01 PM
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

bool can(int v, int n, int k) { 
    int writtenLines = 0;
    while (v > 0) {
        writtenLines += v;
        if (writtenLines >= n) break;
        v /= k;
    }
 
    return writtenLines >= n;
}
 

void Ramez() {
    int n, k; cin >> n >> k;
 
    int l = 0, r = 1e9;
    while (l + 1 < r) {
        int v = (l + r) / 2;
 
        if (can(v, n, k)) r = v;
        else l = v;
    }
 
    cout << r;
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