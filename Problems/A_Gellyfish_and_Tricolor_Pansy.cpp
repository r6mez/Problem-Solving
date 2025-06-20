/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// A. Gellyfish and Tricolor Pansy
// URL: https://codeforces.com/contest/2116/problem/A
// Time: 5/31/2025, 9:45:59 PM
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

void Ramez(int t) {
    // cout << t << " ";
    int a, b, c, d; cin >> a >> b >> c >> d;

    if(min(a, c) >= min(b, d)){
        cout << "Gellyfish\n";
    } else {
        cout << "Flower\n";
    }
}

/*
NOTES:

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez(t);
    return 0;
}