/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all it remained were fields of dreamless solitude.
*/
// D. Skibidus and Sigma
// URL: https://codeforces.com/contest/2065/problem/D
// Time: 2/9/2025, 6:10:43 PM
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
    int n, m; cin >> n >> m;
    vector<vi> a(n, vi(m));

    for (int i = 0; i < n; i++){
        cin >> a[i]; 
        if(m > 1) partial_sum(all(a[i]), a[i].begin());
    }

    sort(all(a), [&](vi &x, vi &y){
        if(x[m-1] == y[m-1]) {
            return x > y;
        } 

        return x[m-1] > y[m-1];
    });

    vi sum;
    for (int i = 0; i < n; i++){
        sum.push_back(a[i][0]);
        for (int j = 1; j < m; j++){
            sum.push_back(a[i][j] - a[i][j-1]);
        }
    }

    if(sum.size() > 1) partial_sum(all(sum), sum.begin());

    int ans = accumulate(all(sum), 0LL);

    cout << ans << '\n';
}

/*
NOTES:
4 4 = 8
4 8
6 1 = 7
6 7 

4 + 8 + 14 + 15 +  = 41

4 5 7 8
4 1 2 1 = 8
2 4 6 8
2 2 2 2 = 8
3 5 6 8
3 2 1 2 = 8

2 2 2 2 = 8
4 1 2 1 = 8
3 2 1 2 = 8

2 + 4 + 6 + 8 + 12 + 13 + 15 + 16 + 19 + 21 + 22 + 24 +  = 162

3 4 5 = 12
3 7 12
1 1 9 = 11
1 2 11 
*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}

