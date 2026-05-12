// E. Great XOR
// URL: https://codeforces.com/group/Rilx5irOux/contest/643069/problem/E
// Time: 5/10/2026, 6:24:16 PM
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

void solve() {
    int x; cin >> x;

    // int x = 170;
    // for(int i = 0; i < x; i++){
    //     if((i ^ x) > x) {
    //         cout << i << " : ";
    //         std::bitset<32> binary(i);
    //         cout << binary << "\n";

    //     }
    // }
    
    
    int LMB = 0;

    for(int i = 62; i >= 0; i--){
        if(x & (1LL << i)){
            LMB = i;
            break;
        }
    }

    // for each zero with index i: iC1 + iC2 + ... + iCi = 2^i
    int count = 0;
    for(int i = LMB - 1; i >= 0; i--){
        if((x & (1LL << i)) == 0){
            count += (1LL << i);
        }
    }

    cout << count << "\n";
}

/*
(y ^ x) > x
y < x

*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}