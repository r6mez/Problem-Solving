/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all it remained were fields of dreamless solitude.
*/
// A. IQ test
// URL: https://codeforces.com/problemset/problem/25/A
// Time: 2/4/2025, 10:07:54 PM
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


void Ramez() {
    int n; cin >> n;
    vi a(n); cin >> a;
    int even = 0, odd = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2) odd++; else even++;
    }

    for (int i = 0; i < n; i++) {
        if (even > odd) {
            if (a[i] % 2) {
                cout << i + 1;
                return;
            }
        }
        else {
            if (a[i] % 2 == 0) {
                cout << i + 1;
                return;
            }
        }
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

