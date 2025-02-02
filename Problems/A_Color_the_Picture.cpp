/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all it remained were fields of dreamless solitude.
*/
// A. Color the Picture
// URL: https://codeforces.com/problemset/problem/1710/A
// Time: 1/22/2025, 4:37:57 PM
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
    int n, m, k; cin >> n >> m >> k;
    vi a(k); cin >> a;

    ll totalHorizontal = 0, oddHorizontal = 0;
    for (int i = 0; i < k; i++) {
        int stripes = a[i] / m;
        if((stripes >= 2 && stripes % 2 == 1) || stripes >= 3) {
            oddHorizontal++;
        }
        if (stripes >= 2) {
            totalHorizontal += stripes;
        }
    }
    if (totalHorizontal >= n && (n % 2 == 0 || oddHorizontal)) {
        cout << "Yes\n";
        return;
    }

    ll totalVertical = 0, oddVertical = 0;
    for (int i = 0; i < k; i++) {
        int stripes = a[i] / n;
        if((stripes >= 2 && stripes % 2 == 1) || stripes >= 3) {
            oddVertical++;
        }
        if (stripes >= 2) {
            totalVertical += stripes;
        }
    }

    if (totalVertical >= m && (m % 2 == 0 || oddVertical)) {
        cout << "Yes\n";
        return;
    }

    cout << "No\n";
}

/*
NOTES:
4 6 3
12 9 8
2  1 1 row stripes (4 rows)
3  2 2 col stripes (6 cols)

3 3 2
8 8
2 2 row stripes (3 rows)
2 2 col stripes (3 cols)

5 4 2
9 11
2 2 row stripes (5 rows)
1 2 col stripes (4 columns)
*/

int main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}

