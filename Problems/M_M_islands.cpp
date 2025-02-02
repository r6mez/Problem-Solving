/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all it remained were fields of dreamless solitude.
*/
// M. M-islands
// URL: https://codeforces.com/group/E23MsQv91X/contest/323789/problem/M
// Time: 1/27/2025, 11:34:50 AM
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi   vector<int>
#define pii  pair<int, int>
#define all(v)  v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
int  dx[] = { -1,   1,   0,   0 }; int  dy[] = { 0,   0,  -1,   1 }; char dir[] = { 'U', 'D', 'L', 'R' };
int MOD = 1000000007;

bool cmp(const pii& a, const pii& b) {
    if (a.first != b.first) return a.first < b.first;
    return a.second > b.second;
}


void Ramez() {
    int n, m; cin >> n >> m;
    vector<pii> ships(n);
    for (int i = 0; i < n; i++) {
        cin >> ships[i].first >> ships[i].second;
    }

    sort(all(ships));

    vector<pii> newShips; newShips.push_back(ships[0]);

    for (int i = 1; i < n; i++) {
        if (newShips.back().second >= ships[i].first) newShips.back().second = max(newShips.back().second, ships[i].second);
        else newShips.push_back(ships[i]);
    }

    int q; cin >> q;
    while (q--) {
        int u, v; cin >> u >> v;
        if (u > v) swap(u, v);

        auto it = lower_bound(all(newShips), make_pair(u, 0ll));
        
        if (it == newShips.end() || it->first > u) --it;

        if (it->first <= u && v <= it->second) cout << "YES\n"; 
        else cout << "NO\n";
    }

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

