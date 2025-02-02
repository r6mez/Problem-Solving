/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all it remained were fields of dreamless solitude.
*/
// B. Clockwork
// URL: https://codeforces.com/contest/2062/problem/B
// Time: 1/26/2025, 4:49:26 PM
#include <bits/stdc++.h>
using namespace std;
#define ll   long long
#define vi   vector<int>
#define vll  vector<ll>
#define pll  pair<ll, ll>
#define all(v)  v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
int MOD = 1000000007;
const int  dx[] = { -1,   1,   0,   0 };
const int  dy[] = { 0,   0,  -1,   1 };
const char dir[] = { 'U', 'D', 'L', 'R' };


void Ramez() {
    int n; cin >> n;
    vi a(n); cin >> a;
    for (int i = 0; i < n; i++){
        int lengthLeft = 2 * i + 1;
        int lengthRight = 2 * (n - 1 - i) + 1;
        int maxLength = max(lengthLeft, lengthRight);
        // cout << maxLength << " ";
        if (maxLength > a[i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

/*
NOTES:
5 3 5
> r
4 3 4 
> r
3 2 5
< r
2 3 4 
< r
5 2 3   
*/

int main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}