// J. Mundo Game
// URL: https://codeforces.com/group/Rilx5irOux/contest/640620/problem/J
// Time: 4/24/2026, 7:10:25 PM
#include <bits/stdc++.h>
#include <functional>
#include <numeric>
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
    int n, k; cin >> n >> k;
    vi a(n + 1); for(int i = 1; i <= n; i++) cin >> a[i];

    function<bool(int)> can = [&](int d) -> bool {   
        vi alive(n + 5);
        for (int i = 1; i <= n; i++) {
            int die_time = i + ceil((double)a[i] / d);
            alive[i]++; 
            if(die_time <= n) alive[die_time]--;
        }

        partial_sum(all(alive), alive.begin());

        for (int i = 1; i <= n; i++) { 
            if(alive[i] >= k) return false;
        }

        return true;
    };

    int l = 0, r = 1e9;
    while(l + 1 < r){
        int mid = (l + r)/2;
        if(can(mid)) r = mid;
        else l = mid;
    }

    cout << r << "\n";
}

/*
for k and n monsters
each second from 1..n the i-th monster comes in
if there's >= k monsters alive he loses
else all alive mosnters loses d health.
what's the minimum d such that he wins

L L L W W W W

it's BS
but I need to find a way to check for a d if he wins or loses
for each a[i] it gets hit by n - i + 1 = x times
i may know when exactly the monster i is born and when he dies, 
it's born at second i and dies at ceil(a[i] / d) + 1
then i get through the d * n seconds and check the total number of alive 
partial sum
*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}