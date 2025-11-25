/*
    One day, I'm gonna grow wings
*/
// G. Beautiful Tree
// URL: https://codeforces.com/problemset/problem/2162/G
// Time: 10/27/2025, 8:49:20 PM
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
        int n;
        cin >> n;
        
        if(n == 2){
            cout << -1 << '\n';
            return;
        }
 
        if(n == 3){
            cout << "1 3\n2 3\n";
            return;
        }

 
        if(n == 4){
            cout << "1 2\n3 1\n4 1\n";
            return;
        }
 
        cout << "1 2\n";
        cout << "2 3\n";
        cout << "3 4\n";
 
        cout << "1 " << n << '\n';
 
        for(int i = 5; i < n; i++) cout << 2 << ' ' << i << '\n';
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