/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all it remained was fields of dreamless solitude.
*/
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

void Ramez() {
    ll n, k; cin >> n >> k;
    vll a(n), b(n); cin >> a >> b;


    vector<pair<int, int>> customers;
    for (int i = 0; i < n; ++i) {
        customers.emplace_back(a[i], b[i]);
    }

    sort(all(customers));
    vll dp(k + 1, 0);

    for (int i = 0; i < n; ++i) {
        int ai = customers[i].first;
        int bi = customers[i].second;

        for (int j = k; j > 0; --j) {
            dp[j] = max(dp[j], dp[j - 1] + bi);
        }
        dp[0] += ai; // Include positive review earnings
    }

    // Maximum earnings with up to k negative reviews
    long long max_earnings = *max_element(dp.begin(), dp.end());
    cout << max_earnings << "\n";
}

/*
NOTES:
if(p <= a[i]) pos
if(a[i] < p <= b[i]) negative
else nothing happen

negative <= k
*/

int main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}

