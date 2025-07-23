/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// C. I Will Definitely Make It
// URL: https://codeforces.com/contest/2126/problem/C
// Time: 7/17/2025, 5:46:07 PM
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
    vi a(n); cin >> a;
    int curr = a[k - 1];
    sort(all(a));
    int start = upper_bound(all(a), curr) - a.begin() - 1;
    int water = 1;
    for (int i = start; i < n - 1; i++){
        if(a[i + 1] - a[i] > (a[i] + 1) - water){
            cout << "NO\n";
            return;
        } 

        water += a[i + 1] - a[i];
    }
    cout << "YES\n";
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