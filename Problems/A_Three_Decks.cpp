/*
    I thought I could bring an end to the world's suffering,
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// A. Three Decks
// URL: https://codeforces.com/contest/2104/problem/0
// Time: 4/28/2025, 5:38:22 PM
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

void Ramez() {
    int a, b, c; cin >> a >> b >> c;
    int sum = a + b + c;
    if(sum % 3 != 0){
        cout << "NO\n";
        return;
    }

    if(2*b - a <= c) cout << "YES\n";
    else cout << "NO\n";
}

/*
NOTES:
1 2 4
2 2 3

3 5 10
5 5 8
6 6 6

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}