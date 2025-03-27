/*
    I thought I could bring an end to the world's suffering,
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// C. Combination Lock
// URL: https://codeforces.com/contest/2091/problem/C
// Time: 3/25/2025, 4:57:51 PM
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
    if(n%2 == 0) {
        cout << -1 << "\n";
        return;
    }

    for (int i = n; i >= 1; i--){
        cout << i << " ";
    }
    cout << "\n";
}

/*
NOTES:
1 2 3 4
4 3 2 1
1 4 3 2
2 1 4 3
3 2 1 4

1 2 3 4 5
5 4 3 2 1 
1 5 4 3 2 
2 1 5 4 3
3 2 1 5 4
4 3 2 1 5

1 2 3
1 3 2
2 1 3
3 2 1 
*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}