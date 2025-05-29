/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// C. Ropes Connection
// URL: https://codeforces.com/group/Rilx5irOux/contest/608858/problem/C
// Time: 5/29/2025, 3:11:57 PM
#include <bits/stdc++.h>
using namespace std;
#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("ropes.in", "r", stdin); }
const int MOD = 1000000007;

void Ramez() {
    int n; cin >> n;
    string s; cin >> s; 
    int cnt = 0;
    for (int i = 0; i < n -1; i++){
        if(s[i] == s[i + 1]) cnt++;
    }
    cout << cnt << "\n";
}

/*
NOTES:

*/

int32_t main() {
    UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}