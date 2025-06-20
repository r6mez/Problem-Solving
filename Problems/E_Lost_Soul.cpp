/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// E. Lost Soul
// URL: https://codeforces.com/contest/2117/problem/E
// Time: 6/8/2025, 7:40:44 PM
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
    vi a(n), b(n); cin >> a >> b;

    if(a.back() == b.back()) {
        cout << n << endl;
        return;
    }

    vi seen(n + 1);

    int x = -1;
    for(int i = n - 2; i >= 0; i--) {
        if(a[i] == b[i] || a[i] == a[i + 1] || b[i] == b[i + 1] || seen[a[i]] || seen[b[i]]) {
            x = i;
            break;
        }

        seen[a[i + 1]] = seen[b[i + 1]] = true;
    }

    cout << x + 1 << endl;
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