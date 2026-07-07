// I. Itsy Bits
// URL: https://codeforces.com/group/zZYq310uLQ/contest/699485/problem/I
// Time: 6/25/2026, 1:10:57 PM
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

void solve() {
 int n, bits= 0 ; cin >> n ;
 while(n){
    bits++;
    n>>=1;
 }
 int ans =1 ;
 while(ans<bits)
 {
    ans<<=1;
 }
 cout << ans << " " << (ans == 1 ? "bit":"bits");

}

/*

*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) solve();
}