// ﷽
// problem: A. Lights Out
// URL: https://codeforces.com/problemset/problem/275/A  
// Start: 5/5/2024, 8:10:42 PM
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vll vector<long long>

void solve() {
    vector<vector<int>> mat(3, vector<int>(3, 1));

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int light; cin >> light;
            light %= 2; 
            if (light == 1) {
                mat[i][j] ^= 1;
                if (i - 1 >= 0) mat[i - 1][j] ^= 1;
                if (j - 1 >= 0) mat[i][j - 1] ^= 1;
                if (i + 1 < 3) mat[i + 1][j] ^= 1;
                if (j + 1 < 3) mat[i][j + 1] ^= 1;
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << mat[i][j];
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}