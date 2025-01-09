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
template<typename T> ostream& operator<<(ostream& os, vector<T>& v){ for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v){ for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
int MOD = 1000000007;

vector<vll> prefixSum2D(vector<vll>& a) {
    vector<vll> b(a.size(), vll(a[0].size()));
    for (int i = 0; i < a.size(); i++) {
        partial_sum(all(a[i]), b[i].begin());
    }
    for (int i = 0; i < a[0].size(); i++) {
        for (int j = 1; j < a.size(); j++) {
            b[j][i] += b[j - 1][i];
        }
    }
    return b;
}

ll sumOfSquare(ll x1, ll y1, ll x2, ll y2, vector<vll>& a) {
    return (a[x2][y2] - a[x1 - 1][y2] - a[x2][y1 - 1]) + a[x1 - 1][y1 - 1];
}

void Ramez() {
    int n, q; cin >> n >> q;
    int size = 1005;
    vector<vll> a(size, vll(size, 0));

    for (int i = 0; i < n; i++){
        int h, w; cin >> h >> w;
        a[h][w] += h*w;
    }
    
    a = prefixSum2D(a);

    for (int i = 0; i < q; i++){
        int hs, ws, hb, wb; cin >> hs >> ws >> hb >> wb;
        cout << sumOfSquare(hs + 1, ws + 1, hb - 1, wb - 1, a) << "\n";
    }
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

