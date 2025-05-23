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

void Ramez() {
    ll n; cin >> n;
    vll a(n); cin >> a;
    sort(all(a));

    if (n == 2) {
        if (a[0] * 2 > a[1]) cout << "YES\n";
        else cout << "NO\n";
        return;
    }

    for (int i = 1; i < n - 1; i++) {
        if (a[i - 1] + a[i] > a[i + 1]) {
            if (a[i - 1] * 2 > a[i + 1]) {
                cout << a[i - 1] << " " << a[i] << " " << a[i + 1] << "\n";
                cout << "YES\n";
                return;
            }
        }
    }

    for (int i = 1; i < n; i++) {
        if (a[i - 1] + a[i - 1] > a[i]) {
            cout << a[i - 1] << " " << a[i] << "\n";
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
}

/*
NOTES:

*/

int main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}

