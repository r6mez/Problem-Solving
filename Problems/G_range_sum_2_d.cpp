/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all it remained were fields of dreamless solitude.
*/
// G. range sum 2d
// URL: https://codeforces.com/group/c3FDl9EUi9/contest/262795/problem/G
// Time: 2/15/2025, 5:26:15 PM
#include <bits/stdc++.h>
using namespace std;
#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
int MOD = 1000000007;

vector<vi> prefixSum2D(vector<vi> &mat){
    vector<vi> preMat(mat.size(), vi(mat[0].size()));

    for (int i = 0; i < mat.size(); i++){
        partial_sum(all(mat[i]), preMat[i].begin());
    }
    
    for (int i = 0; i < mat[0].size(); i++){
        for (int j = 1; j < mat.size(); j++){
            preMat[j][i] += preMat[j - 1][i];
        }
    }
    
    return preMat;
}

int sumOfSquare(int x1, int y1, int x2, int y2, vector<vi>& mat){
    int sum = mat[x2][y2] - mat[x1 - 1][y2] - mat[x2][y1 - 1] + mat[x1 - 1][y1 - 1];
    return sum;
}

void Ramez() {
    int n, m, q; cin >> n >> m >> q;
    vector<vi> mat(n+1, vi(m+1));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> mat[i][j];
        }
    }

    vector<vi> preMat = prefixSum2D(mat);
    
    while(q--){
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        int sum = sumOfSquare(x1, y1, x2, y2, preMat);
        cout << sum << "\n";
    }
}

/*
NOTES:

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}

