#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
#define endl "\n"
#define foor for (ll i = 0; i < n; i++)
#define sz size()
#define vi vector<ll>
#define pii pair<ll,ll>
#define all(x) (x).begin(), (x).end()
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define yn cout << "YES\n"; else cout << "NO\n"
#define pb push_back
template <typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template <typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
#define vv ll n; cin >> n; vi v(n); cin >> v;

const ll N = 1e5 + 13;
const ll MOD = 1000000007;


void Ahshk_el_gambary() {
    ll total, day; cin >> total >> day;
    vector<int> a(total + 2, 0);

    while(day--) {
        int l, r;
        cin >> l >> r;
        a[l]++;
        a[r + 1]--;
    }


    for (int i = 1; i <= total; i++) {
        a[i] += a[i - 1];
    }

    int ans = 0;
    int len = 0;
    for (int i = 1; i <= total; i++) {
        if (a[i] == 0) {
            len++;
        }
        else {
            ans = max(ans, len);
            len = 0;
        }
    }
    ans = max(ans, len);
    cout << ans;
}

int main() {
    fast;
    ll T = 1; //cin>>T;
    while (T--) {
        Ahshk_el_gambary();
    }
    return 0;
}
