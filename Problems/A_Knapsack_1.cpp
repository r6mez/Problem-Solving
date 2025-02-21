/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all that remained were fields of dreamless solitude.
*/
// A - Knapsack 1
// URL: https://vjudge.net/contest/694790#problem/A
// Time: 2/20/2025, 11:37:02 PM
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
    int n, w; cin >> n >> w;
    vector<int> weight(n), value(n);
    for (int i = 0; i < n; i++) cin >> weight[i] >> value[i];

    vector<vi> memo(n + 1, vi(w + 1, -1));

    function<int(int, int)> dp = [&](int i, int currW){
        if(i == n) return 0ll;
        if(memo[i][currW] != -1) return memo[i][currW];

        if(currW + weight[i] > w){ // can't take
            return dp(i + 1, currW);
        }
        
        int leave = dp(i + 1, currW);
        int take = value[i] + dp(i + 1, currW + weight[i]);

        return memo[i][currW] = max(take, leave);
    };

    int answer = dp(0,  0);
    cout << answer << "\n";
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

