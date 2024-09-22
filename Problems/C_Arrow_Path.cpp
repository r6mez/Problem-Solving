// Ramez Medhat
// problem: C. Arrow Path
// URL: https://codeforces.com/problemset/problem/1948/C  
// Start: 7/10/2024, 6:56:39 PM
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

void solve() {
    int n; cin >> n;
    vector<string> graph(2);
    cin >> graph[0] >> graph[1];

    // bfs
    vector<vector<bool>> visited(2, vector<bool>(n));
    queue<pair<char, pair<int, int>>> q;
    q.push({ graph[0][0], {0, 0} });

    while (!q.empty()) {
        auto [c, pir] = q.front(); q.pop();
        auto [i, j] = pir;
        if (visited[i][j]) continue;
        visited[i][j] = true;

        if (i == 1 && j == n - 1) {
            cout << "YES\n";
            return;
        }

        if (!(i == 0 && j == 0)) {
            if (c == '>') j++;
            if (c == '<') j--;
            visited[i][j] = true;
        }

        if (i == 1 && j == n - 1) {
            cout << "YES\n";
            return;
        }

        if (j != n - 1) q.push({ graph[i][j + 1], {i, j + 1} });
        if (j != 0) q.push({ graph[i][j - 1], {i, j - 1} });
        if (i != 1) q.push({ graph[i + 1][j], {i + 1, j} });
        if (i != 0) q.push({ graph[i - 1][j], {i - 1, j} });
    }
    cout << "NO\n";
}

/*
NOTES:

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