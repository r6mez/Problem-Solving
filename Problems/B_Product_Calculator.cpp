/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// B - Product Calculator
// URL: https://atcoder.jp/contests/abc406/tasks/abc406_b
// Time: 5/19/2025, 3:57:50 PM
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
    unsigned int n, k; cin >> n >> k;
    vector<unsigned int> a(n); cin >> a;
    unsigned int num = 1;

    string s = "";    
    for (int i = 0; i < n; i++){
        num *= a[i];
        if(to_string(num).size() > k) num = 1;
    }
    
    cout << num << "\n";
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