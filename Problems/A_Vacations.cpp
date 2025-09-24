/*
    One day, I'm gonna grow wings
*/
// A. Vacations
// URL: https://codeforces.com/problemset/problem/698/A
// Time: 9/10/2025, 9:15:18 PM
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
const int MOD = 1000000007;

const int N = 101;
int dp[N][3];

int n;
vi a;

int cnt(int i, int last){ // last = {0 rest, 1 contest, 2 gym}
    if(i == n) return 0;

    int &p = dp[i][last];
    if(p != -1) return p;

    if(a[i] == 0){
        return p = cnt(i + 1, 0) + 1;
    } 

    if(a[i] == 1){
        if(last == 1) return p = cnt(i + 1, 0) + 1;
        return p = cnt(i + 1, 1);
    }

    if(a[i] == 2){
        if(last == 2) return p = cnt(i + 1, 0) + 1;
        return p = cnt(i + 1, 2);
    }

    if(a[i] == 3) {
        if(last == 1) return p = cnt(i + 1, 2);
        if(last == 2) return p = cnt(i + 1, 1);
        return p = min(cnt(i + 1, 1), cnt(i + 1, 2));    
    }
}

void solve() {
    cin >> n; 
    a.resize(n);
    cin >> a;
    memset(dp, -1, sizeof(dp));
    cout << cnt(0, 0);
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