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
    int n, m; cin >> n >> m;
    string s; cin >> s;
    vector<vll> mat(n, vll(m));
    vll rs(n), cs(m);
    vll rc(n);

    for (int i = 0; i < n; i++) {
        cin >> mat[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            rs[i] += mat[i][j];
            cs[j] += mat[i][j];
        }
    }


    int y = 0, x = 0; // j, i
    rc[y]++; 
    // cout << rc << "\n";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'D') {
            y++;
        }
        else {
            x++;
        }
        rc[y]++;
    }

    // cout << rc << "\n";

    y = 0, x = 0;

    for (int i = 0; i < s.size(); i++) {
        // cout << i << " : " << rc[x] << " " << cs[x] << "\n";
        if (rc[y] > 1) {
            // sum based on column
            mat[y][x] = -cs[x];
        }
        else {
            // sum based on row
            mat[y][x] = -rs[y];
        }

        cs[x] += mat[y][x];
        rs[y] += mat[y][x];

        rc[y]--;

        if (s[i] == 'D') {
            y++;
        } else {
            x++;
        }
    }

    mat[n - 1][m - 1] = -cs[x];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }

}

/*
NOTES:
0 2 3
0 0 0
3 1 0

-5  2   3
2  -3   1
3   1   -4

0  1  0  2  3
0  0  0  0  0
-1 0 -3 -3  0
0  0  0 -1  0

-6  1  0  2   3
7  -1  3  2 -11
-1  0 -3 -3   7
0   0  0 -1   1
*/

int main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}

