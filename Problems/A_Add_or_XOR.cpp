/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// A. Add or XOR
// URL: https://codeforces.com/contest/2119/problem/0
// Time: 7/5/2025, 5:37:28 PM
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
    int a, b, x, y; cin >> a >> b >> x >> y;
    if(a > b){
        if((a ^ 1) == b) {
            cout << y << "\n";
            return;
        }
        cout << "-1\n";
        return;
    }

    int cost = 0;
    if(x < y){
        cost += (b - a) * x;
    } else {
        while(a < b){
            if(a & 1){
                cost += x;
                a++;
            } else {
                cost += y;
                a ^= 1;
            }
        }
    }

    cout << cost << "\n";
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