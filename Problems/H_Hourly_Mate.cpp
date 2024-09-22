// Ramez Medhat
// problem: H. Hourly Mate
// URL: https://codeforces.com/group/qxlLGDBwj5/contest/529356/problem/H  
// Start: 7/2/2024, 12:05:32 PM
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <numeric>
using namespace std;
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vll vector<long long>
#define all(v)  v.begin(), v.end()
#define search(vec, item) find(all(vec), item) != vec.end()

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for (const auto& i : v) os << i << ' ';
    return os;
}

template<typename T>
istream& operator>>(istream& is, vector<T>& v) {
    for (auto& i : v) is >> i;
    return is;
}

bool can(int k, vector<vector<int>>& a) {
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1; i < a.size(); i++) {
        for (int j = 0; j < k; j++) {
            q.push(a[i][j]);
        }
    }
    int cur = 0;
    while (!q.empty()) {
        if (q.top() < cur) break;
        q.pop();
        cur++;
    }
    return q.empty();
}

void solve() {
    int n, m; cin >> n >> m;
    vi types(n);
    vector<vi> typesHours(m+1);

    for (int i = 0; i < n; i++) {
        cin >> types[i];
    }
    for (int i = 0; i < n; i++) {
        int h; cin >> h;
        typesHours[types[i]].push_back(h);
    }

    int mi = INT_MAX;
    for (int i = 1; i <= m; i++) {
        sort(typesHours[i].rbegin(), typesHours[i].rend());
        mi = min((int)typesHours[i].size(), mi);
    }

    int r = mi;
    int l = 1;
    int k = 0;

    while (r >= l) {
        int mid = (r + l) / 2;
        if (can(mid, typesHours)) {
            l = mid + 1;
            k = mid;
        }
        else {
            r = mid - 1;
        }
    }
    cout << k << "\n";
}

/*
NOTES:
assume k = 1
check every type
    if we can take from each type k -> k++
    if not k-- and print(k);

take from each the one with lowest time.

there are n Mate drinks in the machine,
each belonging to some type In total, there are m different types of Mate.
Additionally, each Mate drink will expire in b hours and cannot be sold after that.
As a serious Mate addict, Sascha buys and consumes one Mate every hour.

what is the biggest integer k such that Sascha can consume k Mate of every type?

4 2 1 3 2
3 3 1 7 2

1 2 3 4 --> k
1 2 2 4 3
1 2 3 3 7
• • - • •
h = 7

T
0 1
1 2 3
2 7
3 3

*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

/***
 * ┌───┐   ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┐
 * │Esc│   │ F1│ F2│ F3│ F4│ │ F5│ F6│ F7│ F8│ │ F9│F10│F11│F12│ │P/S│S L│P/B│  ┌┐    ┌┐    ┌┐
 * └───┘   └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┘  └┘    └┘    └┘
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌───┬───┬───┐ ┌───┬───┬───┬───┐
 * │~ `│! 1│@ 2│# 3│$ 4│% 5│^ 6│& 7│* 8│( 9│) 0│_ -│+ =│ BacSp │ │Ins│Hom│PUp│ │N L│ / │ * │ - │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┼───┼───┤ ├───┼───┼───┼───┤
 * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │{ [│} ]│ | \ │ │Del│End│PDn│ │ 7 │ 8 │ 9 │   │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ └───┴───┴───┘ ├───┼───┼───┤ + │
 * │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │: ;│" '│ Enter  │               │ 4 │ 5 │ 6 │   │
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤     ┌───┐     ├───┼───┼───┼───┤
 * │ Shift  │ Z │ X │ C │ V │ B │ N │ M │< ,│> .│? /│  Shift   │     │ ↑ │     │ 1 │ 2 │ 3 │   │
 * ├─────┬──┴─┬─┴──┬┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤ ┌───┼───┼───┐ ├───┴───┼───┤ E││
 * │ Ctrl│    │Alt │         Ramez         │ Alt│    │    │Ctrl│ │ ← │ ↓ │ → │ │   0   │ . │←─┘│
 * └─────┴────┴────┴───────────────────────┴────┴────┴────┴────┘ └───┴───┴───┘ └───────┴───┴───┘
 */
