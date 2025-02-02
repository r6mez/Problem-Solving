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
    int n; cin >> n;

    vll a(n), b(n); cin >> a >> b;

    ll rem = 0;
    multiset<ll> ms;

    for (int i = 0; i < n; ++i) {
        ms.insert(a[i] + rem);
        ll sum = 0;
        while (!ms.empty() && *ms.begin() - rem <= b[i]){
            if (*ms.begin() - rem > 0) {
                sum += *ms.begin();
                sum -= rem;
            }
            ms.erase(ms.begin());
        }
        sum += (b[i] * ms.size());
        if (ms.empty())
            rem = 0;
        else
            rem += b[i];
        cout << sum << " ";
    }
    cout << endl;
}

/*
NOTES:
10 20 15
1  12 9
0  6  9


*/

int main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}

