/*
    One day, I'm gonna grow wings
*/
// C. Creative Snap
// URL: https://codeforces.com/problemset/problem/1111/C
// Time: 9/22/2025, 8:12:56 PM
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

int n, k, A, B; 
vi pos;

int calc(int l, int r){
    if(l == r) {
        if(binary_search(all(pos), l)) return B;
        return A;
    }

    int mid = (l + r) / 2;
    int op1 = calc(l, mid) + calc(mid + 1, r);
  
    int na = upper_bound(all(pos), r) - lower_bound(all(pos), l);
    int op2 = na > 0 ? B * na * (r - l + 1) : A;
    return min(op1, op2);
}

void solve() {
    cin >> n >> k >> A >> B;
    pos.resize(k);
    cin >> pos;
    cout << calc(1, 1 << n);
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