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
    ll n, x, y; cin >> n >> x >> y;
    x--; y--;

    vll p(n);
    for (int i = 0; i < n; i++) {
        if ((i + 1) % 2 == 1) p[i] = 1;
        else p[i] = 0;
    }

    if (n % 2 == 1) p[n - 1] = 2;

    if (p[x] == p[y]) {
        if (x == 1 && y == n - 2) {
            p[n - 2] = 2;
            p[n - 1] = 0;
        } 
        else if (x == 0 && y == n - 3) {
            p[n - 1] = 1;
            p[0] = 2;
        } 
        else if (x == 0 || x == 1) {
            p[y] = 2;
        } else {
            p[x] = 2;
        }
    }

    cout << p << "\n";
}

/*
NOTES:
No condition
even
101010 okay
odd
1010102 okay

With condition
new friends are not the same number
we won't need to change any thing

if the new frieds are the same
we change one of them into two,
we select the one with no two next to it.
*/

int main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}

