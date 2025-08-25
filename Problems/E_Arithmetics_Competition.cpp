/*
    One day, I'm gonna grow wings
*/
// E. Arithmetics Competition
// URL: https://codeforces.com/contest/2132/problem/E
// Time: 8/21/2025, 7:01:47 PM
#include <bits/stdc++.h>
using namespace std;
#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> auto& operator<<(auto& o, vector<T>& v) { for (auto& e : v) o << e << ' '; return o; }
template<typename T> auto& operator>>(auto& i, vector<T>& v) { for (auto& e : v) i >> e; return i; }
void FastIO() { cin.tie(nullptr)->sync_with_stdio(false); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007;

void solve() {
    int n, m, q; cin >> n >> m >> q;
    vi a(n), b(m); cin >> a >> b;

    sort(all(a), greater<int>());
    sort(all(b), greater<int>());


    vi prefA(n + 1, 0);
    vi prefB(m + 1, 0);

    for (int i = 0; i < n; ++i) prefA[i + 1] = prefA[i] + a[i];
    for (int i = 0; i < m; ++i) prefB[i + 1] = prefB[i] + b[i];


    vi pickedA(n + m + 1, 0);
    int itA = 0, itB = 0;
    for (int z = 1; z <= n + m; ++z) {
        pickedA[z] = pickedA[z - 1];

        if (itB >= m) {
            pickedA[z]++;
            itA++;
            continue;
        }

        if (itA < n && a[itA] >= b[itB]) {
            pickedA[z]++;
            itA++;
            continue;
        }

        itB++;
    }

    while (q--) {
        int x, y, z; cin >> x >> y >> z;
        int ulimitA = min(z, x), llimitA = max(0LL, z - y);
        int cntA = min(ulimitA, max(llimitA, pickedA[z]));
        cout << prefA[cntA] + prefB[z - cntA] << "\n";
    }
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