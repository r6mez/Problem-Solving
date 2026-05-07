// J. Gad and primes
// URL: https://codeforces.com/group/Rilx5irOux/contest/636158/problem/J
// Time: 5/4/2026, 2:48:58 PM
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
    int n; cin >> n;
    vi a(n); cin >> a;
    int twos = 0, threes = 0;
    for(int x : a) {
        if(x == 1){
            cout << "-1\n";
            return;
        } else if (x == 2) {
            twos++;
        } else {
            threes++;
        }
    } 

    if(n >= 4){
        cout << "-1\n";
        return;
    }

    if(n == 1){
        cout << a[0] << "\n"; 
    } else if (n == 2) {
        if(twos == threes) cout << "2 3\n";
        else cout << "-1\n";
    } else {
        if(twos == 2 && threes == 1) {
            cout << "2 3 2\n";
        } else {
            cout << "-1\n";
        }
    }
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