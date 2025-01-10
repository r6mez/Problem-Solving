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
    ll n, h; cin >> n >> h;
    vi a(n); cin >> a;

    sort(all(a));

    ll h1 = h, h2 = h, h3 = h;

    ll ass1 = 0, green1 = 2, blue1 = 1;
    for (int i = 0; i < n; i++) {
        bool quit = false;
        while (a[i] >= h1) {
            if (blue1) {
                h1 *= 3;
                blue1--;
            }
            else if (green1) {
                h1 *= 2;
                green1--;
            }
            else {
                quit = true;
                break;
            }
        }

        if (quit) break;

        h1 += a[i] / 2;
        ass1++;
    }

    ll ass2 = 0, green2 = 2, blue2 = 1;
    for (int i = 0; i < n; i++) {
        bool quit = false;
        while (a[i] >= h2) {
            if (green2) {
                h2 *= 2;
                green2--;
            }
            else if (blue2) {
                h2 *= 3;
                blue2--;
            }
            else {
                quit = true;
                break;
            }
        }

        if (quit) break;

        h2 += a[i] / 2;
        ass2++;
    }

    ll ass3 = 0, green3 = 2, blue3 = 1;
    for (int i = 0; i < n; i++) {
        bool quit = false;
        while (a[i] >= h3) {
            if (green3 == 2) {
                h3 *= 2;
                green3--;
            }
            else if (blue3) {
                h3 *= 3;
                blue3--;
            } else if (green3 == 1) {
                h3 *= 2;
                green3--;
            }
            else {
                quit = true;
                break;
            }
        }

        if (quit) break;

        h3 += a[i] / 2;
        ass3++;
    }

    cout << max({ass1, ass2, ass3}) << "\n";
}

/*
NOTES:
2
1 2 8 9

4
15
2

4 1
1 1 2 15
1 -> 3 -> 3 -> 3 -> 4 -> 8 -> 16
0 -> 0 -> 1 -> 2 -> 3 -> 3 -> 4

1 -> 2 -> 2 -> 2 -> 4 -> 5 -> 15
0 -> 0 -> 1 -> 2 -> 2 -> 3 -> X

3 3
2 6 60
3 -> 4 -> 8 -> 11 -> 22 -> 66 -> 96
0 -> 1 -> 1 -> 2  -> 2  -> 2  -> 3

3 -> 4 -> 12 -> 15 -> 30 -> 60
0 -> 1 -> 1  -> 2  -> 2  -> X
*/

int main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}

