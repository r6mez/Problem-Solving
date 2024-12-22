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
template<typename T> ostream& operator<<(ostream& os, vector<T>& v){ for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v){ for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
int MOD = 1000000007;

void Ramez() {
    ll n, x, y; cin >> n >> x >> y;
    vll a(n); cin >> a;
    sort(all(a));
    ll sum = 0;
    for(ll &i : a) sum += i;

    ll pairs = 0;
    for (int i = 0; i < n-1; i++){
        ll maxJ = sum - a[i] - x;
        auto it1 = upper_bound(a.begin()+i+1, a.end(), maxJ);
        ll maxJIndex = (--it1) - a.begin();


        ll minJ =  sum - y - a[i];
        auto it2 = lower_bound(a.begin()+i+1, a.end(), minJ);
        ll minJIndex = it2 - a.begin();

        // cout << minJ << " " << maxJ << "\n";
        // cout << minJIndex << " " << maxJIndex << "\n\n";
        pairs += (maxJIndex - minJIndex + 1);
    }
    
    cout << pairs << "\n";
}

/*
NOTES:
4 8 10
3 4 6 6
sum = 19
(3, 6)
(3, 6)
(4, 6)
(4, 6)

*/

int main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}

