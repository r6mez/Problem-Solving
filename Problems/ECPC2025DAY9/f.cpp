#include <bits/stdc++.h>
using namespace std;
#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007;


void Ramez() {
    int n, m; cin >> n >> m;
    vi x[n];
    vi y[n];
    int res = 0;
    vi arr;
    for(int i = 1; i <= 5; i++) {
        arr.push_back(pow(i*m, 2));
    }
    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        double d = pow(x, 2) + pow(y, 2);
        for(int i = 0; i < 5; i++) {
            if (d <= arr[i]) {
                res += (5-i);
                break;
            }
        }
    }

    cout << res << endl;
}

/*

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}