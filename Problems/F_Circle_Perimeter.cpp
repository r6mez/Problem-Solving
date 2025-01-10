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
    ll r; cin >> r; 
    ll h = r, answer = 0;  

    for (ll y = 0; y <= r; y++) {  // Iterate over y from 0 to r
        // Adjust h so that y^2 + h^2 < (r + 1)^2
        while (y * y + h * h >= (r + 1) * (r + 1)) { 
            h--;
        }

        // Count the number of valid x values for the current y
        ll x = h;
        while (y * y + x * x >= r * r && x > 0) {
            x--;
            answer++;
        }
    }

    // Multiply by 4 to account for all four quadrants
    cout << answer * 4 << "\n";
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

