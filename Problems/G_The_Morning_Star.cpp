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

void Ramez() {
    int n; cin >> n;
    map<ll, ll> xs, ys, fd, bd; 
    ll counter = 0;

    for (int i = 0; i < n; i++){
        ll x, y; cin >> x >> y;
        counter += xs[x] * 2;
        counter += ys[y] * 2;
        counter += fd[y - x] * 2;
        counter += bd[y + x] * 2;
        xs[x]++;
        ys[y]++;
        fd[y - x]++;
        bd[y + x]++;
    }
    cout << counter << "\n";
}

/*
NOTES:
any pair counts as 2 
vaild pairs:
- has same x
- has same y
- slope = 1 or -1 
    = y2 - x2 = y1 - x1
    = y2 + x2 = y1 + x1
*/

int main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}

