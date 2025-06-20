/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// B. Fibonacci Cubes
// URL: https://codeforces.com/contest/2111/problem/B
// Time: 6/3/2025, 5:49:51 PM
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
    int n, m; cin >> n >> m;

    int fn = 2, fnn = 1;
    for (int i = 3; i <= n; i++){
        int temp = fn + fnn;
        fnn = fn;
        fn = temp;
    }
    

    while(m--){
        int w, l, h; cin >> w >> l >> h;
        if(w >= fn && l >= fn && h >= fn + fnn) cout << 1;
        else if(h >= fn && l >= fn && w >= fn + fnn) cout << 1;
        else if(w >= fn && h >= fn && l >= fn + fnn) cout << 1;
        else cout << 0;
    }
    
    cout << "\n";
}

/*
NOTES:
1 2 3 5 8

5 4
3 1 2
10 10 10
9 8 13
14 7 20

2 6
3 2 2

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}