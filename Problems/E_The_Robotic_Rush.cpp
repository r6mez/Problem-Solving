// E. The Robotic Rush
// URL: https://codeforces.com/contest/2185/problem/E
// Time: 1/19/2026, 12:56:42 PM
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
    int n, m, k; cin >> n >> m >> k;
    vi robots(n); cin >> robots;
    vi spikes(m); cin >> spikes;
    string moves; cin >> moves;

    sort(all(spikes));

    vi lTime(k + 1, INF), rTime(k + 1, INF);
    int currOffset = 0, minOffset = 0, maxOffset = 0;
    
    for (int i = 0; i < k; i++) {
        if (moves[i] == 'L') currOffset--;
        else currOffset++;

    
        if (currOffset < minOffset) {
            minOffset = currOffset;
            if (-minOffset <= k) lTime[-minOffset] = i;
        }
    
        if (currOffset > maxOffset) {
            maxOffset = currOffset;
            if (maxOffset <= k) rTime[maxOffset] = i;
        }
    }

    vi results(k, 0);
    
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(all(spikes), robots[i]);
        
        int distL = INF, distR = INF;
        if (it != spikes.end()) distR = *it - robots[i];
        if (it != spikes.begin()) distL = robots[i] - *prev(it);
        

        int timeDie = INF;
        if (distL <= k) timeDie = min(timeDie, lTime[distL]);
        if (distR <= k) timeDie = min(timeDie, rTime[distR]);
        if (timeDie <= k) results[timeDie]--;
    }
    
    partial_sum(all(results), results.begin());
    for (int i = 0; i < k; i++){
        cout << n + results[i] << " ";
    } cout << "\n";
}

/*
calc for each move it's offset {offset, mv}
then for each robot if the spike to the left is L and the spike to the right is R
find the first mv with offset >= min(abs(posR - posRobot), abs(posL - posRobot))
make a partial sum for the mvs that affect each robot
*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}