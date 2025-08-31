/*
    One day, I'm gonna grow wings
*/
// A. Painting With Two Colors
// URL: https://codeforces.com/contest/2134/problem/0
// Time: 8/26/2025, 5:35:29 PM
#include <bits/stdc++.h>
using namespace std;
#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { cin.tie(nullptr)->sync_with_stdio(false); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007;

bool isEven(int n){
    return n % 2 == 0;
}

bool isOdd(int n){
    return n % 2 == 1;
}

void solve() {
    int n, a, b; cin >> n >> a >> b;
    if(isEven(n)){
        if(isOdd(b)){
            cout << "NO\n";
            return;
        }

        if(isEven(a)){
            cout << "YES\n";
            return;
        }

        if(b >= a){
            cout << "YES\n";
            return;
        }

        cout << "NO\n";
    } else {
        if(isEven(b)){
            cout << "NO\n";
            return;
        }

        if(isOdd(a)){
            cout << "YES\n";
            return;
        }

        if(b >= a){
            cout << "YES\n";
            return;
        }

        cout << "NO\n";
    }
}

/*
if n is even
    - b must be even
        else no
    - if a is even ok 
    - if a is odd and b >= a ok
        else no

if n is odd 
    - b must be odd

*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}