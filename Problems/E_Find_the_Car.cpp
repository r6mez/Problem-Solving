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
int MOD = 1000000007;

void Ramez() {
    ll n, k, q; cin >> n >> k >> q;
    vll a(k), b(k); cin >> a >> b;

    a.insert(a.begin(), 0);
    b.insert(b.begin(), 0);

    while(q--){
        ll d; cin >> d;

        auto it = lower_bound(a.begin(), a.end(), d);

        if(*it == d){
            ll i = it - a.begin();
            ll ans = b[i];
            cout << ans << " ";
            continue;
        }

        it--;

        ll r = it - a.begin();
        ll totalTime = b[r] + (d-a[r])*(b[r+1]-b[r])/(a[r+1]-a[r]);

        cout << totalTime << " ";
    }

    cout << "\n";
}

/*
NOTES:

*/

int main() {
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}

