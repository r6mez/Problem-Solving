// C. MTI or MIT
// URL: https://codeforces.com/group/Rilx5irOux/contest/640620/problem/C
// Time: 4/23/2026, 4:59:18 PM
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
    int mti = INT_MAX, mit = INT_MAX;
    int curr = 0;
    for (int i = 0; i < n; i+=3) { if(s[i] != 'm') curr++; if(i + 1 < n && s[i + 1] != 't') curr++; if(i + 2 < n && s[i + 2] != 'i') curr++; } mti = min(mti, curr); curr = 0;
    for (int i = 0; i < n; i+=3) { if(s[i] != 't') curr++; if(i + 1 < n && s[i + 1] != 'i') curr++; if(i + 2 < n && s[i + 2] != 'm') curr++; } mti = min(mti, curr); curr = 0;
    for (int i = 0; i < n; i+=3) { if(s[i] != 'i') curr++; if(i + 1 < n && s[i + 1] != 'm') curr++; if(i + 2 < n && s[i + 2] != 't') curr++; } mti = min(mti, curr); curr = 0;

    for (int i = 0; i < n; i+=3) { if(s[i] != 'm') curr++; if(i + 1 < n && s[i + 1] != 'i') curr++; if(i + 2 < n && s[i + 2] != 't') curr++; } mit = min(mit, curr); curr = 0;
    for (int i = 0; i < n; i+=3) { if(s[i] != 'i') curr++; if(i + 1 < n && s[i + 1] != 't') curr++; if(i + 2 < n && s[i + 2] != 'm') curr++; } mit = min(mit, curr); curr = 0;
    for (int i = 0; i < n; i+=3) { if(s[i] != 't') curr++; if(i + 1 < n && s[i + 1] != 'm') curr++; if(i + 2 < n && s[i + 2] != 'i') curr++; } mit = min(mit, curr); curr = 0;

    if(mti < mit) {
        cout << "mti " << mti << "\n";
    } else if (mti > mit) {
        cout << "mit " << mit << "\n";
    } else {
        cout << "FAKE" << "\n";
    }
}

/*
mtimtimti
mti tim imt
mitmitmit
mit itm tmi
*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) solve();
}