/*
    I thought I could bring an end to the world's suffering,
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// B. Large Array and Segments
// URL: https://codeforces.com/contest/2086/problem/B
// Time: 4/3/2025, 4:41:18 PM
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
    int n, k, x; cin >> n >> k >> x;
    vi a(n); cin >> a;
    
    vi sum(n); 
    sum[n-1] = a[n-1];
    for (int i = n - 2; i >= 0; i--){
        sum[i] = a[i] + sum[i + 1];
    }
    
    int count = 0;
    for (int j = 0; j < n; j++){
        // searching for i (0 .. k - 1)
        int l = 0, r = k + 1;
        while(l + 1 < r) {
            int i = (l + r)/2;
            if(sum[j] + sum[0] * (k - (i)) >= x) l = i;
            else r = i;
        }
        count += l;
    }

    cout << count << "\n";
}

/*
NOTES:

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}