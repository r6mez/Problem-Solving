/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all it remained were fields of dreamless solitude.
*/
// D. Skibidus and Sigma
// URL: https://codeforces.com/contest/2065/problem/D
// Time: 2/9/2025, 6:10:43 PM
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

    int sum = 0;
    for (int i = 0; i < n; i++){
        int sum2 = 0;
        for (int j = 0; j <= i; j++){
            sum2 += a[j];   
        }
        cout << sum2 << " + ";
        sum += sum2;
    }
    cout << " = " << sum << "\n";
}

/*
NOTES:
4 5 7 8
4 1 2 1 = 8

2 4 6 8
2 2 2 2 = 8

3 5 6 8
3 2 1 2 = 8

2 2 2 2 = 8
4 1 2 1 = 8
3 2 1 2 = 8

2 + 4 + 6 + 8 + 12 + 13 + 15 + 16 + 19 + 21 + 22 + 24 +  = 162
*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}

