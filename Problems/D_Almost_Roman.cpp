/*
    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⣀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠳⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⣀⡴⢧⣀⠀⠀⣀⣠⠤⠤⠤⠤⣄⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠘⠏⢀⡴⠊⠁⠀⠀⠀⠀⠀⠀⠈⠙⠦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⣰⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⢶⣶⣒⣶⠦⣤⣀⠀
⠀⠀⠀⠀⠀⠀⢀⣰⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣟⠲⡌⠙⢦⠈⢧
⠀⠀⠀⣠⢴⡾⢟⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⡴⢃⡠⠋⣠⠋
⠐⠀⠞⣱⠋⢰⠁⢿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣠⠤⢖⣋⡥⢖⣫⠔⠋⠀⠀
⠈⠠⡀⠹⢤⣈⣙⠚⠶⠤⠤⠤⠴⠶⣒⣒⣚⣩⠭⢵⣒⣻⠭⢖⠏⠁⢀⣀⠀⠀⠀
⠠⠀⠈⠓⠒⠦⠭⠭⠭⣭⠭⠭⠭⠭⠿⠓⠒⠛⠉⠉⠀⠀⣠⠏⠀⠀⠘⠞⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠓⢤⣀⠀⠀⠀⠀⠀⠀⣀⡤⠞⠁⠀⣰⣆⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠘⠿⠀⠀⠀⠀⠀⠈⠉⠙⠒⠒⠛⠉⠁⠀⠀⠀⠉⢳⡞⠉⠀⠀⠀⠀⠀

*/
// D. Almost Roman
// URL: https://codeforces.com/contest/2170/problem/D
// Time: 11/29/2025, 1:06:35 PM
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
    int n, q; cin >> n >> q;
    string s; cin >> s;

    int base = 0, bonusSlots = 0, marks = 0, marksPairs = 0, minus = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'X') {
            base += 10;
        }
        else if (s[i] == 'V') {
            base += 5;
        }
        else if (s[i] == 'I') {
            if(i + 1 < n && (s[i + 1] == '?')) bonusSlots++;
            if (i + 1 < n && (s[i + 1] == 'X' || s[i + 1] == 'V')) {
                base -= 1;
            } else {
                base += 1;
            }
        } else {
            if(i + 1 < n && s[i + 1] == '?') marksPairs++;
            else if(i + 1 < n && s[i + 1] != 'I') minus++;
            marks++;
        }
    }

    while (q--) {
        int cX, cV, cI;
        cin >> cX >> cV >> cI;

        if(cI >= marks) {
            cI = marks;
            cV = 0;
            cX = 0;
        } else if (cI + cV >= marks){
            cV -= (cI + cV - marks);
            cX = 0;
        } else {
            cX -= (cI + cV + cX - marks);
        }

        int ans = base;

        ans += 10 * cX + 5 * cV + cI;
        
        ans -= 2 * min(cI, minus);
        cI = max(0LL, cI - minus);

        int pairs = min({cI, cX + cV, marksPairs});
        ans -= 2 * pairs;

        int leftoverXV = (cX + cV) - pairs;
        int bonusUsed = min(leftoverXV, bonusSlots);
        ans -= 2 * bonusUsed;

        cout << ans << '\n';
    }
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