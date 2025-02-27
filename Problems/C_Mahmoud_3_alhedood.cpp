/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all that remained were fields of dreamless solitude.
*/
// C. Mahmoud 3alhedood
// URL: https://codeforces.com/group/6aLUitEJUs/contest/590944/problem/C
// Time: 2/25/2025, 8:44:52 PM
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

int  dx[] = { -1,   1,   0,   0 }; int  dy[] = { 0,   0,  -1,   1 }; char dir[] = { 'U', 'D', 'L', 'R' };

void Ramez() {
    int n, m; cin >> n >> m;

    // int answer = 2;

    // for (int i = 2; i <= n; i++){
    //     answer = (answer * 2) % MOD;
    // }

    // for (int i = 2; i <= m; i++){
    //     answer = (answer * 2) % MOD;
    // }
    
    // for (int i = 2; i <= n; i++){
    //     for (int j = 2; j <= m; j++){
    //         answer = (answer * 2) % MOD;
    //     }
    // }
    
    // cout << answer << "\n";
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

