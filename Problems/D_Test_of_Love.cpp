// Ramez Medhat
// problem: D. Test of Love
// URL: https://codeforces.com/contest/1992/problem/D  
// Start: 7/11/2024, 6:22:07 PM
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
const int MOD = 1000000007;
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
    int n, m, k; cin >> n >> m >> k;
    string s; cin >> s;

    queue<pair<int, int>> q;
    vector<bool> visited(n + 2);

    q.push({ -1, 0 });
    visited[0] = true; 

    while (!q.empty()) {
        auto [pos, water] = q.front(); q.pop();

        if (pos == n) {
            cout << "YES\n";
            return;
        }

        for (int jump = 1; jump <= m; jump++) {
            int i = pos + jump;

            if(s[pos] == 'W' && jump >= 2) break;;

            if (i >= n) {
                cout << "YES\n";
                return;
            }

            if (!visited[i + 1] && s[i] != 'C') {
                if (s[i] == 'W') {
                    if (water + 1 <= k) {
                        q.push({ i, water + 1 });
                        visited[i + 1] = true;
                    }
                }
                else {
                    q.push({ i, water });
                    visited[i + 1] = true;
                }
            }
        }
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