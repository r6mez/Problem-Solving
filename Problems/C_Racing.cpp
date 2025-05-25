/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// C. Racing
// URL: https://codeforces.com/contest/2110/problem/C
// Time: 5/24/2025, 6:13:38 PM
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
    int n; cin >> n;
    vi d(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }

    vi l(n + 1), r(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
    }

    vi up(n + 1), down(n + 1);
    for (int i = 1; i <= n; i++) {
        if (d[i] == 0) {
            down[i] = max(down[i - 1], l[i]);
            up[i] = min(up[i - 1], r[i]);
        } else if (d[i] == 1) {
            down[i] = max(down[i - 1] + 1, l[i]);
            up[i] = min(up[i - 1] + 1, r[i]);
        } else if(d[i] == -1) {
            down[i] = max(down[i - 1], l[i]);
            up[i] = min(up[i - 1] + 1, r[i]);
        }
        
        if (down[i] > up[i]) {
            cout << -1 << '\n';
            return;
        }
    }

    vi h(n+1);
    int cur = up[n];
    for(int i = n; i >= 1; i--) {
        if(d[i] == 0) {
            h[i] = 0;
        } else if(d[i] == 1) {
            h[i] = 1;
            cur--;  
        } else {
            if(cur - 1 >= down[i-1] && cur - 1 <= up[i-1]) {
                h[i] = 1;
                cur--;
            } else {
                h[i] = 0;
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << h[i] << " ";
    }
    cout << "\n";
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