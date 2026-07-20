// D. Median Solve Order
// URL: https://codeforces.com/group/zZYq310uLQ/contest/702561/problem/D
// Time: 7/15/2026, 2:06:11 PM
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

__int128 fact(__int128 x){
    __int128 result = 1;
    for(int i = 2; i <= x; i++)
        result *= i;   
    return result;  
}

void solve() {
    int n; cin >> n;
    __int128 med = (fact(n) + 1) / 2 - 1;

    string letters;
    for (int i = 0; i < n; i++) letters += char('A' + i);

    string s;
    for (int i = 0; i < n; i++) {
        __int128 block = fact(n - i - 1);
        int idx = med / block;
        med %= block;
        s += letters[idx];
        letters.erase(letters.begin() + idx);
    }
    cout << s << "\n";
}

/*

*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}