/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all it remained were fields of dreamless solitude.
*/
// C. Customer Service
// URL: https://codeforces.com/contest/2059/problem/C
// Time: 2/6/2025, 1:54:01 PM
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
    vector<vi> a(n, vi(n));

    multiset<int> s;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }

        int ones = 0;
        for (int j = n - 1; j >= 0; j--) {
            if (a[i][j] == 1) ones++;
            else break;
        }
        s.emplace(ones);
    }
    
    for (int i = 0;; i++) {
        auto it = s.lower_bound(i);
        if (it == s.end()) {
            cout << i << "\n";
            return;
        }
        s.erase(it);
    }
}

/*
NOTES:
1 0
3 2

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}

