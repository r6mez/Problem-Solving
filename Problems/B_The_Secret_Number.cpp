/*
    One day, I'm gonna grow wings
*/
// B. The Secret Number
// URL: https://codeforces.com/contest/2132/problem/B
// Time: 8/21/2025, 5:40:46 PM
#include <bits/stdc++.h>
using namespace std;
#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> auto& operator<<(auto& o, vector<T>& v) { for (auto& e : v) o << e << ' '; return o; }
template<typename T> auto& operator>>(auto& i, vector<T>& v) { for (auto& e : v) i >> e; return i; }
void FastIO() { cin.tie(nullptr)->sync_with_stdio(false); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007;

void solve() {
    int n; cin >> n;
    vi answers;

    int tens = 10;

    for (int i = 0; i <= 18; i++){
        int c = 1 + tens;
        if(n % c == 0)answers.push_back(n / c);
        tens *= 10;
    }
    
    sort(all(answers));
    cout << answers.size() << "\n";
    cout << answers << "\n";
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