/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all that remained were fields of dreamless solitude.
*/
// C. Solve Equation
// URL: https://codeforces.com/group/c3FDl9EUi9/contest/264941/problem/C
// Time: 2/19/2025, 10:34:22 PM
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
    double c, time; cin >> c >> time;
    
    double l = 0, r = 1e10;
    while(l + 0.000001 < r){
        double mid = (l + r) / 2;
        if(c * mid * log2(mid) <= time) l = mid;
        else r = mid;
    }
    
    cout << fixed << setprecision(9) << l << "\n";
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

