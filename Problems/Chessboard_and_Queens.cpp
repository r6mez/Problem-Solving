/*
    One day, I'm gonna grow wings
*/
// Chessboard and Queens
// URL: https://cses.fi/problemset/task/1624/
// Time: 10/11/2025, 2:44:56 PM
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

int n = 8; 
vector<string> board(n);
vi col(n), mainDia(2 * n), antiDia(2 * n);

bool can(int i, int j){
    if(board[i][j] == '*') return false;
    if(col[j] || mainDia[n + i - j - 1] || antiDia[i + j]) return false;

    return true;
}

int calc(int i){
    if(i == n){
        return 1;
    }

    int count = 0;
    
    for (int j = 0; j < n; j++){
        if(can(i, j) == false) continue;
        col[j] = mainDia[n + i - j - 1] = antiDia[i + j] = 1;
        count += calc(i + 1);
        col[j] = mainDia[n + i - j - 1] = antiDia[i + j] = 0;
    }
    
    return count;
}


void solve() {
    cin >> board;
    cout << calc(0);
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