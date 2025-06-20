/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// B. Make It Permutation
// URL: https://codeforces.com/contest/2118/problem/B
// Time: 6/13/2025, 1:53:46 PM
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
    int n; cin >> n;
    cout << n * 2 - 2 << "\n";
    for (int i = 1; i <= n; i++){
        if(i != 1) cout << i << " " << 1 << " " << i << "\n";
        if(i + 1 <= n) cout << i << " " << i + 1 << " " << n << "\n"; 
    }
}

/*
NOTES:
1 2 3
1 2 3
1 2 3

3 2 1 (3)
2 3 1 (2)
1 2 3 (0)

1 2 3 4
1 2 3 4
1 2 3 4
1 2 3 4

4 3 2 1 (4)
3 4 1 2 (3)
2 1 4 3 (2)
1 2 3 4 (0)

1 2 3 4 5              == || ==
1 2 3 4 5                 ||
1 2 3 4 5             === || ===
1 2 3 4 5                 ||
1 2 3 4 5                 \/

1 2 3 4 5
1 2 3 4 5 -> 5 4 3 2 1 -> 5 1 2 3 4
1 2 3 4 5 -> 5 4 3 2 1 -> 4 5 3 2 1 -> 4 5 1 2 3
1 2 3 4 5 -> 5 4 3 2 1 -> 3 4 5 2 1 -> 3 4 5 1 2
1 2 3 4 5 -> 5 4 3 2 1 -> 2 3 4 5 1

1 2 3 4 5
5 1 2 3 4
4 5 1 2 3
3 4 5 1 2
2 3 4 5 1

1 2 3 4 5
1 5 4 3 2
2 1 3 4 5
2 1 5 4 3 
*/


int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}