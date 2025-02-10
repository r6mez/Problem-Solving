/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all it remained were fields of dreamless solitude.
*/
// E1. Game with Marbles (Easy Version)
// URL: https://codeforces.com/contest/1914/problem/E1
// Time: 2/7/2025, 6:55:34 PM
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
    int n; cin >> n;
    vi a(n), b(n); cin >> a >> b;
    
    vi ids(n);
    iota(all(ids), 0);

    sort(all(ids), [&](int i, int j){
        return a[i] + b[i] > a[j] + b[j];
    });
    
    int s = 0;
    for (int i = 0; i < n; i++){
        if(i % 2 == 1){
            s -= b[ids[i]] - 1;
        } else {
            s += a[ids[i]] - 1;
        }
    }

    cout << s << "\n";
}

/*
NOTES:

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}

