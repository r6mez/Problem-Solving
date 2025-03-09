/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all that remained were fields of dreamless solitude.
*/
// H. Zular Eclipse
// URL: https://codeforces.com/group/3nQaj5GMG5/contest/376466/problem/H
// Time: 3/9/2025, 3:59:38 PM
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
    int n; cin >> n;
    vi a(n); cin >> a;
    sort(all(a));
    vi prefix(a);
    partial_sum(all(prefix), prefix.begin());
    int q; cin >> q;
    while(q--){
        int x; cin >> x;
        int count = upper_bound(all(a), x) - a.begin();
        if(count == 0) cout << -1 << '\n';
        else cout << count << ' ' << prefix[count-1] << '\n';
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