/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// G. Hits Different
// URL: https://codeforces.com/problemset/problem/1829/G
// Time: 5/28/2025, 9:02:58 PM
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

vector<vi> prefixSum2D(vector<vi>& a) {
    vector<vi> b(a.size(), vi(a[0].size()));
    for (int i = 0; i < a.size(); i++) {
        partial_sum(all(a[i]), b[i].begin());
    }
    for (int i = 0; i < a[0].size(); i++) {
        for (int j = 1; j < a.size(); j++) {
            b[j][i] += b[j - 1][i];
        }
    }
    return b;
}

int sumOfSquare(int x1, int y1, int x2, int y2, vector<vi>& a) {
    return (a[x2][y2] - a[x1 - 1][y2] - a[x2][y1 - 1]) + a[x1 - 1][y1 - 1];
}

void Ramez() {
    int size = 2e6 + 5;
    vi dp(size);
    vector<vi> a(1500, vi(1500));
    int curr = 1;
    for (int i = 1; i < 1500; i++) {
		for (int j = i - 1; j >= 1; j--) {
			a[j][i - j] = curr * curr;
            curr++;
		}
	}

    a = prefixSum2D(a);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << sumOfSquare(1, 1, n, )
    }

}

/*
NOTES:

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}