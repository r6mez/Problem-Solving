// C. Trivial Problem
// URL: https://codeforces.com/group/zZYq310uLQ/contest/615216/problem/C
// Time: 7/8/2026, 8:46:50 PM
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
    vi a(n); cin >> a;

    vi L(n), R(n);
    stack<int> st;
    
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.top()] <= a[i]) st.pop();
        L[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    while (!st.empty()) st.pop();

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && a[st.top()] <= a[i]) st.pop();
        R[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    vector<int> g(n + 1, 0);
    for (int i = 0; i < n; i++) {
        if (a[i] > n) continue;
        int span = R[i] - L[i] - 1;
        g[a[i]] = max(g[a[i]], span);
        
    }

    vector<vector<int>> dieAt(n + 2);
    for (int v = 0; v <= n; v++)
        dieAt[min(g[v], n) + 1].push_back(v);

    long long cur = LLONG_MAX;
    for (int k = 1; k <= n; k++) {
        for (int v : dieAt[k]) cur = min(cur, (long long)v);
        cout << cur << " ";
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