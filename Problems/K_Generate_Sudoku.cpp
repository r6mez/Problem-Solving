/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all it remained were fields of dreamless solitude.
*/
// K. Generate Sudoku
// URL: https://codeforces.com/group/E23MsQv91X/contest/323789/problem/K
// Time: 1/27/2025, 10:35:14 AM
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi   vector<int>
#define pii  pair<int, int>
#define all(v)  v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
int  dx[] = { -1,   1,   0,   0 }; int  dy[] = { 0,   0,  -1,   1 }; char dir[] = { 'U', 'D', 'L', 'R' };
int MOD = 1000000007;


void Ramez() {
    vector<vi> sud(9, vi(9));

    for (int i = 0; i < 9; i++) {
        cin >> sud[0][i];
    }


    for (int i = 1; i < 9; i++) {
        if (i % 3 == 0) {
            for (int j = 0; j < 9; j++) {
                sud[i][j] = sud[i - 1][(j + 1) % 9];
            }
        }
        else {
            for (int j = 0; j < 9; j++) {
                sud[i][j] = sud[i - 1][(j + 3) % 9];
            }
        }
    }

    for (int i = 0; i < 9; i++) {
        cout << sud[i] << "\n";
    }

}

/*
NOTES:
i/3
5 4 1 6 2 7 9 3 8
6 2 7 9 3 8 5 4 1
9 3 8 5 4 1 6 2 7
4 1 6 2 7 9 3 8 5
2 7 9 3 8 5 4 1 6
3 8 5 4 1 6 2 7 9
1 6 2 7 9 3 8 5 4
7 9 3 8 5 4 1 6 2
8 5 4 1 6 2 7 9 3
*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}

