/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// A. Energy Crystals
// URL: https://codeforces.com/contest/2111/problem/0
// Time: 6/3/2025, 5:35:11 PM
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
    int x; cin >> x;
    int cnt = 3;
    int a = 1;
    while(a < x){
        cnt += 2;
        a = (a * 2) + 1;
    }
    cout << cnt << "\n";
}

/*
NOTES:
0 0 0 
1 0 0
1 1 0
1 1 3
3 1 3
3 7 3
3 7 7
14 7 7
14 14 7
14 14 14

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}