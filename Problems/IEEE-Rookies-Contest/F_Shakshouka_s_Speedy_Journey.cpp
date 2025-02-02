// F. Shakshouka's Speedy Journey
// URL: https://codeforces.com/gym/584099/problem/F
// Time: 2/1/2025, 1:32:30 PM
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
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(k), b(k);
    cin >> a >> b;

    a.insert(a.begin(), 0); b.insert(b.begin(), 0);

    while (q--) {
        int d; cin >> d;
        auto it = lower_bound(all(a), d);

        if (*it == d) {
            int i = it - a.begin();
            cout << b[i] << " ";
            continue;
        }

        it--;
        int r = it - a.begin();
        int totalTime = b[r] + (d - a[r]) * (b[r + 1] - b[r]) / (a[r + 1] - a[r]);
        cout << totalTime << " ";
    }
    cout << endl;
}

/*
NOTES:

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Solve();
    return 0;
}