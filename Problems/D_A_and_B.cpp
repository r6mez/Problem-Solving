/*
    One day, I'm gonna grow wings
*/
// D. A and B
// URL: https://codeforces.com/contest/2149/problem/D
// Time: 9/25/2025, 5:48:03 PM
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
    int n; cin >> n;
    string s; cin >> s;

    vi posA, posB;
    for (int i = 0;i < n;i++) {
        if (s[i] == 'a') posA.push_back(i);
        else posB.push_back(i);
    }

    int cntA = posA.size();
    int cntB = posB.size();

    if (cntA <= 1 || cntB <= 1) finish(0);

    int resA = 0;
    for (int i = 0; i < cntA; i++) resA += abs((posA[i] - i) - (posA[cntA/2] - cntA/2));
    
    int resB = 0;
    for (int i = 0; i < cntB; i++) resB += abs((posB[i] - i) - (posB[cntB/2] - cntB/2));

    cout << min(resA, resB) << "\n";
}

/*
ababababa
aabbbbaaa
*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}