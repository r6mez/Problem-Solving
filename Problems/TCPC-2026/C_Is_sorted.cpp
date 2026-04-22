// C. Is sorted ?
// URL: https://codeforces.com/group/Rilx5irOux/contest/678837/problem/C
// Time: 4/21/2026, 10:08:14 PM
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

int n;
vi a;

int getType(int x, int y, int z){
    if(x == -1 && z == n){
        return 4;
    }

    if(x == -1){
        if(a[y] == a[z]) return 4;
        if(a[y]  < a[z]) return 0;
        if(a[y]  > a[z]) return 1;
    }

    if(z == n){
        if(a[x] == a[y]) return 4;
        if(a[x]  < a[y]) return 0;
        if(a[x]  > a[y]) return 1;    
    }

    if(a[x] == a[y]  && a[y] == a[z]) return 4;
    if(a[x] <= a[y]  && a[y] <= a[z]) return 0;
    if(a[x] >= a[y]  && a[y] >= a[z]) return 1;
    if(a[x] <= a[y]  && a[y] >= a[z]) return 2;
    if(a[x] >= a[y]  && a[y] <= a[z]) return 3;
    
    return -1; // won't happen
}


void solve() {
    cin >> n;
    a.resize(n); cin >> a;

    vector<int> counters(5);

    for(int i = 0; i < n; i++){
        counters[getType(i - 1, i, i + 1)]++;
    }

    int q; cin >> q;
    while(q--){
        int op; cin >> op;
        if(op == 1){
            int i, x; cin >> i >> x; i--;
            counters[getType(i - 1, i, i + 1)]--;
            counters[getType(i, i + 1, i + 2)]--;
            counters[getType(i - 2, i - 1, i)]--;
            a[i] = x;
            counters[getType(i - 1, i, i + 1)]++;
            counters[getType(i, i + 1, i + 2)]++;
            counters[getType(i - 2, i - 1, i)]++;
        } else if (op == 2) {
            if(counters[0] + counters[4] == n) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        } else {
            if(counters[1] + counters[4] == n) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}

/*

0 -> upstair
1 -> downstair
2 -> peak
3 -> base
4 -> line

for each three consective elements x, y, z

x > y > z
then y is upstair
x < y < z 
then y is downstair
x > y < z
the y is base
x < y > z 
then y is peak
x == y == z
then y is line

line adds up to upstair or downstair

we check the count of each one, 
if upstair or downstair + line is n then it's increasing / decreasing
else it's chaotic.
*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) solve();
}