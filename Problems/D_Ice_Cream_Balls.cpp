/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all it remained were fields of dreamless solitude.
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


ll sum(ll k) {
    return k * (k - 1) / 2;
}



void Ramez() {
    ll n;
    cin >> n;
    ll l = 0, r = min<ll>(2e9, 2 * n);
    while (r - l > 1) {
        ll m = (l + r) >> 1;
        // m = x + y, answer = x + 2 * y
        if (m * (m - 1) / 2 + m < n) {
            l = m;
        }
        else {
            r = m;
        }
    }
    ll y = n - r * (r - 1) / 2;
    if ((r + 1) * r / 2 <= n) {
        cout << min(r + y, r + 1 + n - (r + 1) * r / 2) << "\n";
    }
    else {
        cout << r + y << "\n";
    }
}

/*
NOTES:
i (number of polas used)
ai (the max number of icecreams can be made with i pola)
*/

int main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}

