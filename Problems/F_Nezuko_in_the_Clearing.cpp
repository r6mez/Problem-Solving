/*
    One day, I'm gonna grow wings
*/
// F. Nezuko in the Clearing
// URL: https://codeforces.com/contest/2149/problem/F
// Time: 9/25/2025, 6:49:30 PM
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

int sum(int x) {
    return x * (x + 1) / 2;
}

void solve() {
    int h, d; cin >> h >> d;
    int l = -1, r = d + 1; 
    while (l + 1 < r) {
        int rests = (l + r) / 2; 
        int blocks = rests + 1, extraBlocks= d % blocks, blockSize = d / blocks;
        if ((blocks - extraBlocks) * sum(blockSize) + extraBlocks * sum(blockSize + 1) < h + rests) r = rests;
        else l = rests;
    }

    int answer = d + r;
    cout << answer << '\n';
}

/*

*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}