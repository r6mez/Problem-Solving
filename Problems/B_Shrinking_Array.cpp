/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// B. Shrinking Array
// URL: https://codeforces.com/contest/2112/problem/B
// Time: 6/23/2025, 5:46:02 PM
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

    int ops = -1;

    for (int i = 0; i < n - 1; i++){
        if(abs(a[i] - a[i + 1]) <= 1){
            ops = 0;
            break;
        }

        int mn = min(a[i], a[i + 1]), mx = max(a[i], a[i + 1]);
        if(i > 0 && a[i - 1] >= mn && a[i - 1] <= mx){
            ops = 1;
        }

        if(i < n - 2 && a[i + 2] >= mn && a[i + 2] <= mx){
            ops = 1;
        }
    }
    
    cout << ops << "\n";
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