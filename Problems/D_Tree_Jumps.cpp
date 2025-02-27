/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all that remained were fields of dreamless solitude.
*/
// D. Tree Jumps
// URL: https://codeforces.com/contest/2070/problem/D
// Time: 2/27/2025, 5:15:12 PM
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
const int MOD = 998244353;

void Ramez() {
    int n; cin >> n;
    vi a(n - 1); cin >> a;

    vector<vi> tree(n + 1);
    for (int i = 2; i <= n; i++) {
        tree[a[i - 2]].push_back(i);
    }

    queue<int> q; q.push(1);
    vi nodeLevel(n + 1, 0); nodeLevel[1] = 1;
    vi levelCount(n + 1, 0); levelCount[1] = 1;

    while (!q.empty()) {
        int parent = q.front(); q.pop();

        for (int child : tree[parent]) {
            nodeLevel[child] = nodeLevel[parent] + 1;
            levelCount[nodeLevel[child]]++;
            q.push(child);
        }
    }
    

    int answer = 1 + (levelCount[2]);

    vi dp(n + 1, 0); dp[1] = 1; dp[2] = 1;

    for (int i = 3; i <= n; i++) {
        dp[i] = ((dp[i - 1])%MOD * (levelCount[i - 1] - 1)%MOD)%MOD;
        answer = (answer + ((dp[i] % MOD) * (levelCount[i] % MOD))%MOD) % MOD;
    }

    cout << answer << "\n";
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

