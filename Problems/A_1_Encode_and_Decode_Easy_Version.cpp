/*
    One day, I'm gonna grow wings
*/
// A1. Encode and Decode (Easy Version)
// URL: https://codeforces.com/contest/2168/problem/A1
// Time: 11/3/2025, 8:09:31 PM
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

string encode(int x) {
    string s(7, 'a');
    for (int i = 0; i < 7; i++) {
        s[i] = x % 26 + 'a';
        x /= 26;
    }
    return s;
}
 
int decode(string s) {
    int x = 0;
    for (int i = 6; i >= 0; i--) {
        x = x*26 + (s[i] - 'a');
    }
    return x;
}    


void solve() {
    string run; cin >> run;
    
    if(run == "first"){
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            cout << encode(a);
        }
    } else {
        string s; cin >> s;
        cout << s.size()/7 << " ";
        for (int i = 0; i < s.size(); i += 7) {
            string u = s.substr(i, 7);
            cout << decode(u) << " ";
        }
    }
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