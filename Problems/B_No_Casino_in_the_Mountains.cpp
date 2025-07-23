/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// B. No Casino in the Mountains
// URL: https://codeforces.com/contest/2126/problem/B
// Time: 7/17/2025, 5:38:22 PM
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
    int cnt = 0, peak = 0;
    for (int i = 0; i < n; i++){
        if(a[i] == 0){
            cnt++;
        } else {
            cnt = 0;
        }

        if(cnt == k){
            peak++;
            cnt = 0;
            i++;
        }
    }
    cout << peak << "\n";
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