// F. BattleCows
// URL: https://codeforces.com/contest/2185/problem/F
// Time: 1/21/2026, 8:22:31 PM
#include <bits/stdc++.h>
using namespace std;
#define int         long long
#define vi          vector<int>
#define pii         pair<int, int>
#define all(v)      v.begin(), v.end()
#define finish(s)   { cout << s << "\n"; return; }
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { cin.tie(nullptr)->sync_with_stdio(false); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007, INF = 2e18;

void solve() {
    int levelsCnt, q; cin >> levelsCnt >> q;
    int n = 1LL << levelsCnt;
    vi a(n); cin >> a;

    vector<vi> xorLevels;
    xorLevels.push_back(a);

    int level = 1;
    while (true) {
        int size = n / (1LL << level);
        if (size == 0) break;
        vi currentLevel(size);
        for (int i = 0; i < size; i++) {
            currentLevel[i] = xorLevels[level - 1][2 * i] ^ xorLevels[level - 1][2 * i + 1];
        }
        xorLevels.push_back(currentLevel);
        level++;
    }

    while (q--) {
        int x, k; cin >> x >> k; x--;

        int currXor = k, topCnt = 0;
        for (int level = 0; level < levelsCnt; level++) {
            int size = n / (1LL << level);
            int siblingIdx = (x % 2 == 0) ? x + 1 : x - 1;
            if (xorLevels[level][siblingIdx] > currXor) {
                topCnt += (1LL << level);
            }
            else if (xorLevels[level][siblingIdx] == currXor && x % 2 == 1) { // left wins and we are right
                topCnt += (1LL << level);
            }
            currXor ^= xorLevels[level][siblingIdx];
            x /= 2;
        }

        cout << topCnt << "\n";
    }
}

/*
precalculate the whole xor tree
then for each query simulate the path for that element again
it will take n log n

how to calculate and store the xor tree ?
we can do it level by level
Array of levels
for each level we can calculate the xor values using the previous level
size of level is n / (2 ^ level)
we can stop when size becomes 0
*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}