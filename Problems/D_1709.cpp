/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// D. 1709
// URL: https://codeforces.com/contest/2121/problem/D
// Time: 6/17/2025, 6:10:15 PM
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
    int n; cin >> n;
    vi a(n); cin >> a;
    vi b(n); cin >> b;

    vector<pii> answer;
    for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) {
            swap(a[i], b[i]);
            answer.emplace_back(3, i + 1);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                answer.emplace_back(1, j + 1);
            }

            if (b[j] > b[j + 1]) {
                swap(b[j], b[j + 1]);
                answer.emplace_back(2, j + 1);
            }
        }
    }

    cout << answer.size() << "\n";
    for (auto [ops, idx] : answer) {
        cout << ops << " " << idx << "\n";
    }
}

/*
NOTES:
40 + 780 * 2

3 2 1
1 1
2 3 1
1 2
2 1 3
1 1
1 2 3

5 6 1 2
7 8 3 4

1 2 5 6
3 4 7 8

5 1 6 2
5 1 2 6
1 5 2 6

1 2 5 6
3 4 7 8

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}