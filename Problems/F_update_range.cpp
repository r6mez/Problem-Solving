/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all it remained were fields of dreamless solitude.
*/
// F. update range
// URL: https://codeforces.com/group/c3FDl9EUi9/contest/262795/problem/F
// Time: 2/15/2025, 4:57:22 PM
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

    vi counters(n);

    while(q--){
        int l, r, val;
        cin >> l >> r >> val;
        l--; r--;

        counters[l] += val;
        if(r < n - 1) counters[r + 1] -= val;
    }

    partial_sum(all(counters), counters.begin());

    for (int i = 0; i < n; i++){
        cout << a[i] + counters[i] << " ";
    }
}

/*
NOTES:
0 0 0 0 0 0 0 0

0 2 3 0 0 0 -2 -3

0 2 5 5 5 5 3 0


*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}

