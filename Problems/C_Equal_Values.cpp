/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// C. Equal Values
// URL: https://codeforces.com/contest/2111/problem/C
// Time: 6/3/2025, 6:10:45 PM
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
    int n;
    cin >> n;
    vi a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<vi> pos(n + 1);
    vi distinct;

    for (int i = 1; i <= n; i++) {
        int x = a[i];
        if (pos[x].empty()) distinct.push_back(x);
        pos[x].push_back(i);
    }

    int optimal = LLONG_MAX;

    for (int x : distinct) {
        vi& xPos = pos[x];
        int distCnt = xPos.size();
        if (distCnt == n) {
            optimal = min(optimal, 0LL);
            continue;
        }

        int cost = (n - 1) * x;
        int start = 0;
        for (int i = 1; i <= distCnt; i++) {
            if (i == distCnt || xPos[i] != xPos[i - 1] + 1) {
                int left = xPos[start], right = xPos[i - 1];
                int runCost = x * ((left - 1) + (n - right));
                cost = min(cost, runCost);
                start = i;
            }
        }
        
        optimal = min(optimal, cost);
    }

    cout << optimal << "\n";
}

/*
NOTES:
if there's one element different
then an operation must be done
other wise no operation requires


7 (5) 5 (5) 10 9 9 4 6 10

7 5 5 5 10 9 5 5 5 5

5 5 5 5 5 9 5 5 5 5 5

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}