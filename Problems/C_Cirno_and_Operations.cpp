/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all it remained were fields of dreamless solitude.
*/
// C. Cirno and Operations
// URL: https://codeforces.com/contest/2062/problem/C
// Time: 1/26/2025, 6:17:23 PM
#include <bits/stdc++.h>
using namespace std;
#define int long long
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

int maxSum;

void a333(vi &a) {
    if (a.size() == 1) return;

    for (int i = 0; i < a.size() - 1; i++) {
        a[i] = a[i + 1] - a[i];
    }
    a.pop_back();

    int currSum = accumulate(all(a), 0ll);
    maxSum = max({maxSum, currSum, -currSum});

    a333(a);
}

void Ramez() {
    int n; cin >> n;
    vi a(n); cin >> a;

    if (n == 1) {
        cout << a[0] << "\n";
        return;
    }

    maxSum = INT_MIN;

    maxSum = max(maxSum, accumulate(all(a), 0ll));

    a333(a);

    cout << maxSum << "\n";
}


/*
NOTES:
maxSum
a[i] = a[i+1] - a[i]


9 7 9 -9 9 -8 7 -8 9
-3 3
*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}

