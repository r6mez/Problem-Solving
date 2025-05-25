/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// C - Security 2
// URL: https://atcoder.jp/contests/abc407/tasks/abc407_c
// Time: 5/24/2025, 3:09:44 PM
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
    string s; cin >> s;
    int cnt = s.size();
    cnt += (s.back() - '0');

    for (int i = 1; i < s.size(); i++){
        int curr = s[i] - '0';
        int prev = s[i - 1] - '0';
        cnt += (prev - curr + 10)%10;
    }
    
    cout << cnt;
}

/*
NOTES:
407
0
1
2
3
4
40 -> add
51
62
73
730 -> add
841
952
063
174
285
396
407
*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}