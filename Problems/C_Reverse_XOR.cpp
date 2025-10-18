/*
    One day, I'm gonna grow wings
*/
// C. Reverse XOR
// URL: https://codeforces.com/contest/2160/problem/C
// Time: 10/13/2025, 12:08:44 AM
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

bool isSet(int n, int i) {
    return (n & (1LL << i)) != 0;
}

int findLastBit(int n) {
    for (int i = 31; i >= 0; i--) {
        if (isSet(n, i)) return i;
    }
    return -1;
}

bool isSymmtric(int n, int len){
    for (int i = 0; i < len; ++i) {
        if (isSet(n, i) != isSet(n, len - 1 - i)) { return false; }
    }
    return true;
}

void solve() {
    int n; cin >> n;
    if (n == 0) finish("YES");

    int msb = findLastBit(n);

    for (int k = msb + 1; k <= 60; ++k) {
        if(!isSymmtric(n, k)) continue;
        if ((k & 1) && isSet(n, k / 2)) continue; // k is odd and middle is set
        finish("YES");
    }
    
    finish("NO");
}

/*
if last bit index is n
the bit representation of the number must be palindrome around n/2.
*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}