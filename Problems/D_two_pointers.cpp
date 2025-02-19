/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all that remained were fields of dreamless solitude.
*/
// D. two pointers
// URL: https://codeforces.com/group/c3FDl9EUi9/contest/264941/problem/D
// Time: 2/19/2025, 10:46:54 PM
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
    int n, m; cin >> n >> m;
    vi a(n); cin >> a;

    vi prefixSum(n); 
    partial_sum(all(a), prefixSum.begin());

    if(prefixSum[n-1] < m) return void(cout << "-1\n");

    int l = 0, r = 0, minLength = INT_MAX;

    while(l <= n - 1 && r <= n - 1){
        int currSum = prefixSum[r] - (l > 0? prefixSum[l - 1] : 0);
        if(currSum >= m && l <= r) minLength = min(minLength, r - l + 1);

        if(currSum >= m) l++;
        else r++;
    }
    
    cout << minLength << "\n";
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

