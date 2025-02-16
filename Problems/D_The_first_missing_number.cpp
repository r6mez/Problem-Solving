/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all it remained were fields of dreamless solitude.
*/
// D. The first missing number
// URL: https://codeforces.com/group/c3FDl9EUi9/contest/262795/problem/D
// Time: 2/15/2025, 3:41:23 PM
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
int MOD = 1000000007;

void Ramez() {
    int n, q; cin >> n >> q;
    vi a(n); cin >> a;

    vi pre(n);
    pre[0] = a[0];

    for (int i = 1; i < n; i++){
        pre[i] = a[i] + pre[i-1];
    }
    
    while(q--){
        int l, r; cin >> l >> r;
        l--; r--;

        int rangeSum = pre[r] - (l > 0? pre[l-1] : 0); 
        cout << rangeSum << "\n";
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

