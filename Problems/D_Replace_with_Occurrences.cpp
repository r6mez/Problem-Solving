/*
    One day, I'm gonna grow wings
*/
// D. Replace with Occurrences
// URL: https://codeforces.com/contest/2137/problem/D
// Time: 9/7/2025, 6:42:34 PM
#include <bits/stdc++.h>
using namespace std;
#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { cin.tie(nullptr)->sync_with_stdio(false); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007;

void solve() {
    int n; cin >> n;
    vi b(n); cin >> b;

    map<int, vi> groups;
    for (int i = 0; i < n; ++i) {
        groups[b[i]].push_back(i);
    }

    vi a(n);
    int cnt = 1;

    for (auto& [freq, group] : groups) {
        if (group.size() == 0) continue;

        if (group.size() % freq != 0) {
            cout << "-1\n";
            return;
        }

        for (int i = 0; i < group.size(); ++i) {
            a[group[i]] = cnt;
            if ((i + 1) % freq == 0) cnt++;
        }
    }

    cout << a << "\n";
}

/*
you're given the array of ocurrences b
construct a such that f[a[i]] = number of times b[i] appears in b
both must be of size n

*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}