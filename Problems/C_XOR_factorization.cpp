// C. XOR-factorization
// URL: https://codeforces.com/contest/2180/problem/C
// Time: 12/21/2025, 2:24:06 PM
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

bool isSet(int n, int i){
    return n & (i << 1);
}

int setBit(int n, int i){
    return n | (i << 1);
}

void solve() {
    int n, k; cin >> n >> k;
    vi a(k, 0);
    
    vi freq(31);
    for (int b = 30; b >= 0; b--){
        if(n&1){
            if(isSet(n, b)) freq[b] = k;
            else freq[b] = k - 1;
        } else {
            if(isSet(n, b)) freq[b] = k - 1;
            else freq[b] = k;
        }
    }

    for (int b = 30; b >= 0; b--){
        for (int i = 0; i < k; i++){
            if(setBit(a[i], b) <= n && freq[b]){
                a[i] = setBit(a[i], b);
                freq[b]--;
            }
        }  
    }
    
    cout << a << "\n"; 
}


/*
k odd
n, n, n, n, ... k times
k even
n, n, n, n, ... k - 2 times
+ a, b : a ^ b == n & a != b and a + b is maximized.
so a == 0, b == n -> this doesn't give maximum sum.

n = 18 (10010)
a = 17 (10001)
b = 3  (00011)

*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}