/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// B. Two Sets
// URL: https://codeforces.com/contest/468/problem/B
// Time: 6/23/2025, 4:50:41 PM
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
    int n, a, b; cin >> n >> a >> b;
    vi p(n);
    map<int, int> mark, use, ins;
    set<int> st;

    for (int i = 0; i < n; i++) cin >> p[i], mark[p[i]] = 1;

    for (int i = 0; i < n; i++) {
        if (!mark[a - p[i]]) {
            st.insert(p[i]);
            ins[p[i]] = 1;
        }
    }

    while (st.size()) {
        int x = *st.begin(); st.erase(st.begin());

        use[x] = 1;
        if (mark[a - x] == 1 && ins[a - x] == 0) {
            ins[a - x] = 1;
            st.insert(a - x);
        }
        
        if (mark[b - x] == 1 && ins[b - x] == 0) {
            ins[b - x] = 1;
            st.insert(b - x);
        }

        if (mark[b - x] == 0) {
            cout << "NO" << "\n";
            return;
        }
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++) cout << use[p[i]] << ' ';
}

/*
NOTES:

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}