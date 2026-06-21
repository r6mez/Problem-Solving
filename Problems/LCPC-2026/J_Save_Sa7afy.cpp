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
 
const int MAX_VAL = 2e7 + 5;
int spf[MAX_VAL]; 
void sieve() { 
    for (int i = 1; i < MAX_VAL; ++i) {  spf[i] = i;  }
    for (int i = 2; i * i < MAX_VAL; ++i) {
        if (spf[i] == i) { 
            for (int j = i * i; j < MAX_VAL; j += i) {
                if (spf[j] == j) { 
                    spf[j] = i;
                }
            }
        }
    }
}

void solve() {
    int n, k; cin >> n >> k;
    vi a(n); cin >> a;
    sort(all(a));
    int count = 0;
    for(int x : a){
        if(x <= k) {
            k += spf[x];
            count++;
        } else {
            break;
        }
    }
    
    cout << count << " " << k << "\n";    
}
/*

*/

signed main() {
    sieve();
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}