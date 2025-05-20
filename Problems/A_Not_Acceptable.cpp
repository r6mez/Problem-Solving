/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// A - Not Acceptable
// URL: https://atcoder.jp/contests/abc406/tasks/abc406_a
// Time: 5/19/2025, 3:34:27 PM
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
    int h1, m1, h2 ,m2; cin >> h1 >> m1 >> h2 >> m2;

    if(h2 < h1){
        cout << "Yes\n";
        return;
    }

    if(h2 > h1) {
        cout << "No\n";
        return;
    }

    if(m2 <= m1) cout << "Yes\n";
    else cout << "No\n";
}

/*
NOTES:

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}