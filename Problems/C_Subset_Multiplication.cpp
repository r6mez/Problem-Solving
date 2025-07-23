/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// C. Subset Multiplication
// URL: https://codeforces.com/contest/2124/problem/C
// Time: 7/9/2025, 10:04:44 PM
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

    int g = 0, l = 1;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i + 1] % a[i] != 0){
            g = a[i] / gcd(a[i + 1], a[i]);
            l = lcm(l, g);
        }
    }

    if (g == 0) cout << 69 << endl;
    else cout << l << endl;
}

/*
NOTES:
1 3 9
5 15 45
I need to know what's the original ratio is
after that the solution is easy
if(a[i] >= a[i + 1])
    we can say that a[i] is mutliplied by x and a[i + 1] is not


x = a[i + 1] / ratio
*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}