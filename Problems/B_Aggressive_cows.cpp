/*
    I thought I could bring an end to the world's suffering,
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// B. Aggressive cows
// URL: https://codeforces.com/group/c3FDl9EUi9/contest/264941/problem/B
// Time: 3/12/2025, 10:41:06 PM
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

bool can(int d, int c, int n, vi &a){
    int prevCow = a[0];
    int cowCounter = 1;
    
    for (int i = 1; i < n; i++){
        if(a[i] - prevCow >= d) cowCounter++, prevCow = a[i];

        if(cowCounter == c) break;
    }

    return cowCounter >= c;
}

void Ramez() {
    int n, c; cin >> n >> c;
    vi a(n); cin >> a;

    sort(all(a));

    int l = 0, r = 1e9 + 10;
    while(l + 1 < r){
        int mid = l + (r - l)/2;

        if(can(mid, c, n ,a)) l = mid;
        else r = mid;
    }

    cout << l << "\n";
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