/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// A. k-th divisor
// URL: https://codeforces.com/contest/762/problem/A
// Time: 6/25/2025, 7:23:12 PM
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

vi getDivisors(int n) {
    vi divs;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divs.push_back(i);
            if (i * i != n) divs.push_back(n / i);
        }
    }
    return divs;
}

void Ramez() {
    int n, k; cin >> n >> k;
    vi divs = getDivisors(n);
    sort(all(divs));
    if(k > divs.size()) cout << -1;
    else cout << divs[k - 1]; 
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