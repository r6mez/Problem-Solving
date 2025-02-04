// K. Shakshouka's Portal Adventure
// URL: https://codeforces.com/gym/584099/problem/K
// Time: 2/1/2025, 1:32:35 PM
#include <bits/stdc++.h>
using namespace std;
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
    int n, k; cin >> n >> k;
    vi a(n-1); cin >> a;

    a.push_back(0);

    int i = 0;
    while (i <= n && i+1 <= k){
        if(i+1 == k){
            cout << "YES\n";
            return;
        }

        i += a[i];
    }

    if(i == n) cout << "YES\n";
    else cout << "NO\n";
}

/*
NOTES:

*/

int32_t main() {
    // UseFile();
    FastIO();
    Solve();
    return 0;
}

