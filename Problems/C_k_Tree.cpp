/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// C. k-Tree
// URL: https://codeforces.com/problemset/problem/431/C
// Time: 5/5/2025, 10:48:19 PM
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

int n, k, d;

vector<vi> dp(101, vi(2, -1));


int calc(int sum, bool check){
    if(sum > n) return 0;
    if(sum == n) return check;

    int &res = dp[sum][check];
    if(res != -1) return res;

    res = 0;
    for (int i = 1; i <= k; i++){
        res = (res + calc(sum + i, check || (i >= d))) % MOD;
    }

    return res;
}

void Ramez() {
    cin >> n >> k >> d;
    int answer = calc(0, false);
    cout << answer << "\n";
}

/*
NOTES:
3 3 2
1 2
2 1
3

3 3 3
3

4 3 2
1 1 2
1 2 1
2 1 1
2 2
1 3
3 1

4 5 2
1 1 2
1 2 1
1 3 
2 1 1
2 2
3 1 
4 

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}