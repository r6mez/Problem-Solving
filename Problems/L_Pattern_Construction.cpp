/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// L. Pattern Construction
// URL: https://codeforces.com/group/Rilx5irOux/contest/605910/problem/L
// Time: 5/9/2025, 6:17:32 PM
#include <bits/stdc++.h>
using namespace std;
#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("pattern.in", "r", stdin); }
const int MOD = 1000000007;

void Ramez() {
    string a, b; cin >> a >> b;
    int n = a.size(), m = b.size();

    vector<vi> fam(26, vi(n)); vi fb(26);
    for (int i = 0; i < n; i++) fam[a[i] - 'a'][i]++;
    for (int c = 0; c < 26; c++) partial_sum(all(fam[c]), fam[c].begin());
    for (int i = 0; i < m; i++) fb[b[i] - 'a']++;

    function<bool(int, int)> can = [&](int i, int j) -> bool {
        vi fa(26);

        for (int c = 0; c < 26; c++) {
            fa[c] = fam[c][j] - (i > 0 ? fam[c][i - 1] : 0);
        }

        int changeCount = 0, changeChar = -1, diff = 0;
        for (int c = 0; c < 26; ++c) {
            if (fa[c] < fb[c]) {
                changeCount++;
                if (changeCount > 1) return false;
                changeChar = c;
                diff = fb[c] - fa[c];
            }
        }

        if (changeCount == 0) return true;

        for (int o = 0; o < 26; ++o) {
            if (o != changeChar && fb[o] == 0 && fa[o] >= diff)
                return true;
        }

        return false;
    };


    for (int i = 0; i < n; i++) {
        int l = i - 1, r = n;

        while (l + 1 < r) {
            int j = (l + r) / 2;
            if (can(i, j)) r = j;
            else l = j;
        }

        if(r >= n) cout << "-1 ";
        else cout << r + 1 << " ";
    }
    cout << "\n";
}

/*
NOTES:

*/

int32_t main() {
    UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}