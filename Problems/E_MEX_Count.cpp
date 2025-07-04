/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// E. MEX Count
// URL: https://codeforces.com/contest/2123/problem/E
// Time: 7/1/2025, 6:38:51 PM
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
    vi freq(n + 2), prefix(n + 2);
    for (int i = 0; i < n; i++){
        freq[a[i]]++;
    }

    for (int mex = 0; mex <= n; mex++){
        if(mex > 0 && freq[mex - 1] == 0) break;
        if(freq[mex] <= n - mex){
            prefix[freq[mex]]++; prefix[n - mex + 1]--;
        }
    }
    
    partial_sum(all(prefix), prefix.begin());    
    prefix.pop_back();
    cout << prefix << "\n";
}

/*
NOTES:
0 1 2 3 4 
0 0 1 1 2 
1 2 4 3 2 1


6
0 1 1 2 2 3
1 1 2 2


1 3 5 4 3 2 1
1 3 5

if freq[i] <= k and there's enough elements > i that suffuix > k -> I can show this number
*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}