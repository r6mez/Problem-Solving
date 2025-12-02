/*
  الذكرى واخداني لمكان، أيام زمان
*/
// C. Dungeon
// URL: https://codeforces.com/problemset/problem/2164/C
// Time: 12/2/2025, 1:09:19 PM
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

int n, m;
int a[200200], b[200200], c[200200];

void solve() {
    int n, m; cin >> n >> m;
    multiset<int> ms;
    for (int i = 1;i <= n;i++){
        int x;
        cin >> x;
        ms.insert(x);
    }

    for (int i = 1;i <= m;i++)
        cin >> b[i];
    for (int i = 1;i <= m;i++)
        cin >> c[i];
    
        vector<pii> vec;
    int ans = 0;
    for (int i = 1;i <= m;i++)
        if (c[i])
            vec.push_back({b[i], c[i]});
    
    sort(all(vec));

    for (auto [x, y] : vec){
        auto it = ms.lower_bound(x);
        if (it != ms.end())
        {
            ans++;
            y = max(y, *it);
            ms.erase(it);
            ms.insert(y);
        }
    }

    for (int i = 1;i <= m;i++)
        if (!c[i]){
            auto it = ms.lower_bound(b[i]);
            if (it != ms.end())
            {
                ans++;
                ms.erase(it);
            }
        }

    cout << ans << '\n';
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