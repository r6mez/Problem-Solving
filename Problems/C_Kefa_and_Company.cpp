/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all that remained were fields of dreamless solitude.
*/
// C. Kefa and Company
// URL: https://codeforces.com/group/3nQaj5GMG5/contest/376466/problem/C
// Time: 3/9/2025, 2:30:08 PM
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
    int n, d; cin >> n >> d;
    vector<pii> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
    }

    sort(all(a));

    vi pre(n); pre[0] = a[0].second;
    for (int i = 1; i < n; i++){
        pre[i] = a[i].second + pre[i-1];
    }

    int maxMoney = 0;
    for (int i = 0; i < n; i++){
        int j = upper_bound(all(a), make_pair(a[i].first + d, 0LL)) - a.begin();
        j--;
        int currMoney = pre[j] - (i > 0 ? pre[i - 1] : 0);
        maxMoney = max(maxMoney, currMoney);
    }

    cout << maxMoney << "\n";
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