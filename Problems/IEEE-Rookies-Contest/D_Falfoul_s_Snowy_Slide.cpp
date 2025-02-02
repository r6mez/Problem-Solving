// D. Falfoul's Snowy Slide
// URL: https://codeforces.com/gym/584099/problem/D
// Time: 2/1/2025, 1:32:28 PM
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


void Solve() {
    int n; cin >> n;
    vector<vi> a(10, vi(10));

    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        a[x][y]++;
    }

    int total = 0;
    for (int i = 1; i < a.size(); i++) {
        for (int j = 1; j < a.size(); j++) {
            if (a[i][j]) {
                bool hasNighbour = false;
                for (int k = 0; k < 4; k++) {
                    if (a[i + dx[k]][j + dy[k]]) hasNighbour = true;
                }

                if (hasNighbour == false) {
                    queue<pii> q;
                    q.push({ i, j });

                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();

                        if (a[x][y]) {
                            total += abs(x - i) + abs(y - j);
                            for (int q = min(i, x) + 1; q < max(i, x); q++) {
                                a[q][j]++;
                            }
                            for (int q = min(j, y) + 1; q < max(j, y); q++) {
                                a[x][q]++;
                            }

                            cout << i << " " << j << "\n";
                            for (int f = 0; f < a.size(); f++) {
                                cout << a[f] << "\n";
                            }
                            cout << "\n";
                        }
                        else {
                            for (int k = 0; k < 4; k++) {
                                q.push({ i + dx[k], j + dy[k] });
                            }
                        }

                        bool foundN = false;
                    }
                }
            }
        }
    }

    cout << total << "\n";
}

/*
NOTES:

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Solve();
    return 0;
}