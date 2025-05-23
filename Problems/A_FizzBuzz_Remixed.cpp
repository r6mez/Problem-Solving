/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all that remained were fields of dreamless solitude.
*/
// A. FizzBuzz Remixed
// URL: https://codeforces.com/contest/2070/problem/0
// Time: 2/27/2025, 4:35:21 PM
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

    int answer = ((n / 15) * 3) + min(n % 15 + 1, 3LL);

    cout << answer << "\n";

}

/*
NOTES:
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 
0 1 2 0 1 2 0 1 2 0 1  2  0  1  2  0  1  2  0  1  2
0 1 2 3 4 0 1 2 3 4 0  1  2  3  4  0  1  2  3  4  0

every 15 there's 0 1 2
*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}

