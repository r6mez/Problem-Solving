/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all it remained were fields of dreamless solitude.
*/
// D. Coprime
// URL: https://codeforces.com/contest/1742/problem/D
// Time: 2/7/2025, 7:16:10 PM
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

    vi idx(1002);
    for (int i = n - 1; i >= 0; i--) {
        if (!idx[a[i]]) idx[a[i]] = i + 1;
    }

    int maxAns = -1;
    for (int i = 0; i <= 1000; i++) {
        for (int j = i; j <= 1000; j++) {
            if (!idx[i] || !idx[j]) continue;

            if (gcd(a[idx[i]-1], a[idx[j]-1]) == 1) {
                maxAns = max(maxAns, idx[i] + idx[j]);
            }
        }
    }

    cout << maxAns << "\n";
}

/*
NOTES:

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}

