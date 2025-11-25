/*
    One day, I'm gonna grow wings
*/
// B. Fibonaccharsis
// URL: https://codeforces.com/problemset/problem/1853/B
// Time: 10/25/2025, 9:08:04 PM
#include <bits/stdc++.h>
using namespace std;
#define int         long long
#define vi          vector<int>
#define pii         pair<int, int>
#define all(v)      v.begin(), v.end()
#define finish(s)   { cout << s << "\n"; return; }
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { cin.tie(nullptr)->sync_with_stdio(false); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007, INF = 2e18;

int n, k;
int cnt = 0;

void calc(int a, int b, int s){
    if(a < 0 || b < 0) return;
    if(s == k) cnt++;
    calc(b - a, a, s + 1);
}

void solve() {
    cnt = 0;
    cin >> n >> k;
    for (int i = n/2; i <= n; i++){
        calc(i, n, 1);
    }
    cout << cnt << "\n";
}

/*
cout <
we get n
we  need to find 2 numbers their sum must be equal to n

a + b = n
((b - a) +  a) = b
*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}