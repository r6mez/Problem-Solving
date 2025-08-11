/*
    I was alone in an empty universe.
    A universe too small and at the same time... too infinite.
*/
// F. Skibidus and Slay
// URL: https://codeforces.com/problemset/problem/2065/F
// Time: 7/26/2025, 6:39:51 PM
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
    vi value(n); for (int& i : value) cin >> i, i--;
    
    vector<vi> adj(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v; u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    string answer = string(n, '0');
    
    for (int u = 0; u < n; u++) {
        map <int, int> mp;
        for (int v : adj[u]) mp[value[v]]++;
        mp[value[u]]++;
        
        for (auto [value, freq] : mp) if (freq >= 2) answer[value] = '1';
        
    }
    
    cout << answer << '\n';
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