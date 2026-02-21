// F. Fragmented Nim
// URL: https://codeforces.com/problemset/problem/2181/F
// Time: 2/3/2026, 9:03:56 PM
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
    
}

/*
the final game happens if you have to choose only one pile, and you take it all, 
then in the next round the oppenent loses

so to avoid that, you must leave at least 2 piles for the opponent, so one of the is chosen (by you), he selects 
-> if the pile = 1, he has no other choice and you win
-> otherwise he can select 
any move before that, you can greedly remove the whole pile
but watch out 
*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) solve();
}