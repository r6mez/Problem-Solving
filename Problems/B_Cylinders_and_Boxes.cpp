/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// B. Cylinders and Boxes
// URL: https://codeforces.com/group/Rilx5irOux/contest/608858/problem/B
// Time: 5/29/2025, 3:13:24 PM
#include <bits/stdc++.h>
using namespace std;
#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("box.in", "r", stdin);  }
const int MOD = 1000000007;

void Ramez() {
    int r, h; cin >> r >> h;
    int x, y, z; cin >> x >> y >> z;
    int w = r*2;
    if (x >= w && y >= w && z >= h
     or z >= w && y >= w && x >= h
     or x >= w && z >= w && y >= h) cout << "Yes\n";
        else cout << "No\n";
}

/*
NOTES:

*/

int32_t main() {
    UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}