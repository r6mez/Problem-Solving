/*
    I was alone in an empty universe.
    A universe too small and at the same time... too infinite.
*/
// H. Hebron: A City of Ancient Heritage
// URL: https://codeforces.com/group/Rilx5irOux/contest/537316/problem/H
// Time: 7/25/2025, 9:47:31 PM
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
    int n, k; cin >> n >> k;
    vi a(n + 1);
    int x = 1;
    for (int i = 1; i <= n; i++){
        for (int j = i; j <= n; j += k){
            if(a[j] != 0) break;
            a[j] = x++;
        }
    }
    
    for (int i = 1; i <= n; i++){
        cout << a[i] << " ";
    }
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