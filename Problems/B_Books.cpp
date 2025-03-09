/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all that remained were fields of dreamless solitude.
*/
// B. Books
// URL: https://codeforces.com/problemset/problem/279/B
// Time: 3/1/2025, 4:06:08 PM
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
    int n, t; cin >> n >> t;
    vi a(n); cin >> a;

    vi pre(n); pre[0] = a[0];
    for (int i = 1; i < n; i++){
        pre[i] = a[i] + pre[i-1]; 
    }

    // 0 1 2 3
    // 3 1 2 1
    // 3 4 6 7 
    int maxBooks = 0;
    for (int i = 0; i < n; i++){
        int j = lower_bound(pre.begin() + i, pre.end(), t + (i > 0 ? pre[i - 1] : 0)) - pre.begin();
        if(j >= n || pre[j] > t + (i > 0 ? pre[i - 1] : 0)) j--;
        int currBooks = j - i + 1;
        maxBooks = max(maxBooks, currBooks);
    }

    cout << maxBooks << "\n";
}

/*
NOTES:
    pre[j] - pre[i - 1] <= t
    pre[j] <= t + pre[i - 1]

    1 3 5 7 8 
    lower 4 = 5
    upper 5 = 7
*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}

