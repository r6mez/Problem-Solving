/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// J. Crashing Robots
// URL: https://codeforces.com/group/Rilx5irOux/contest/605910/problem/J
// Time: 5/9/2025, 7:09:54 PM
#include <bits/stdc++.h>
using namespace std;
#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
#define F first
#define S second
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("robots.in", "r", stdin); }
const int MOD = 1000000007;

pair<int, int> f(char c, pair<int, int> p) {
    switch (c) {
        case 'U': 
            p.second++;
            break;
        case 'D': 
            p.second--;
            break;
        case 'L':
            p.first--;
            break;
        case 'R': 
            p.first++;
            break;
    }
    return p;
}

void Ramez() {
    int n; cin >> n;
    vector<string> robo(n);
    vector<pair<int, int>> prev(n);
    vector<int> crached(n);
    map<pair<int, int>, map<int, int>> m;

    for (int i = 0; i < n; i++) {
        cin >> robo[i];
        reverse(all(robo[i]));
    }

    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        prev[i] = { x, y };
        m[prev[i]][i] = 1;
    }

    int cnt = 0;
    int flag = 0;
    do {
        flag = 0;
        for (int j = 0; j < n; j++) {
            if (robo[j].empty() || crached[j])
                continue;
            flag = 1;
            auto nmove = f(robo[j].back(), prev[j]);
            m[nmove][j] = 1;
            robo[j].pop_back();
            m[(prev[j])].erase(j);
            if (m[prev[j]].empty())
                m.erase(prev[j]);

            prev[j] = nmove;
        }
        for (auto& [a, b] : m) {
            if (b.size() > 1) {
                for (auto& [j, c] : b) {
                    if (crached[j])
                        continue;
                    robo[j].clear();
                    cnt++;
                    crached[j] = 1;
                }
            }
        }
    } while (flag);
    cout << cnt << "\n";
}

/*
NOTES:

*/

int32_t main() {
    UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}