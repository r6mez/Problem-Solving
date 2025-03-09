/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all that remained were fields of dreamless solitude.
*/
// F. Magic Powder - 2
// URL: https://codeforces.com/group/3nQaj5GMG5/contest/376466/problem/F
// Time: 3/9/2025, 3:19:24 PM
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
    vi a(n), b(n); cin >> a >> b;

    int l = 0, r = 2e9 + 10;
    while(l + 1 < r){
        int mid = (l + r) / 2;
    
        // can she bake (mid) cakaes ?
        bool can = true;
        int currMagic = k;
        for (int i = 0; i < n; i++){
            int deficit = max(0LL, a[i] * mid - b[i]);
            if(deficit > currMagic){
                can = false;
                break;
            } else {
                currMagic -= deficit;
            }
        }
        
        if(can) l = mid;
        else r = mid;
    }

    cout << l;
}

/*
NOTES:
b[i] / a[i] >= mid
b[i] >= a[i] * mid
*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}