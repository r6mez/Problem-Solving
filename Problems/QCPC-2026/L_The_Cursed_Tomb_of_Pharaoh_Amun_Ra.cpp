// L. The Cursed Tomb of Pharaoh Amun-Ra
// URL: https://codeforces.com/group/Rilx5irOux/contest/636158/problem/L
// Time: 5/7/2026, 2:57:26 PM
#include <algorithm>
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
    vector<string> a(n); cin >> a;
    for(string &s : a){
        reverse(all(s));
    }

    string suf;
    for (int i = 0; i < 100; i++) {
        set<char> c;
        
        for(string s : a) {
            if (i >= s.size()) {
                break;
            }

            c.insert(s[i]);
        }

        if(c.size() != 1) {
            break;
        } else {
            suf.push_back(*c.begin());
        }
    }

    if(suf.empty()) {
        cout << "NO\n";
    } else {
        cout << "YES\n";        
        reverse(all(suf));
        cout << suf;
    }
}

/*

*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) solve();
}