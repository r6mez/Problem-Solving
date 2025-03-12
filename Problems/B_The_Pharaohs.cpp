/*
    I thought I could bring an end to the world's suffering,
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// B. The Pharaohs
// URL: https://codeforces.com/group/3nQaj5GMG5/contest/376466/problem/B
// Time: 3/12/2025, 11:15:51 PM
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

int can(int mid, int n){
    return mid * (mid + 1) / 2 >= n;
}

void Ramez() {
    int n; cin >> n;

    int l = 0, r = 1;

    while(can(r, n) == false) r *= 2;

    while(l + 1 < r){
        int mid = (l + r)/2;
        if(can(mid, n)) r = mid;
        else l = mid;
    }
    cout << r << "\n";
}

/*
NOTES:
;
*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}