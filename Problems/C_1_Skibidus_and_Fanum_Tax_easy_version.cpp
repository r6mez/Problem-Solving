/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all it remained were fields of dreamless solitude.
*/
// C1. Skibidus and Fanum Tax (easy version)
// URL: https://codeforces.com/contest/2065/problem/C1
// Time: 2/9/2025, 4:40:25 PM
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
    vi a(n), b(m); cin >> a >> b;

    if(n == 1) {
        cout << "YES\n";
        return;
    }


    if(a[0] > b[0] - a[0]) a[0] = b[0] - a[0];

    for (int i = 1; i < n; i++){
        if((b[0] - a[i] <= a[i] && b[0] - a[i] >= a[i-1]) || (a[i-1] > a[i] && b[0] - a[i] > a[i])) {
            a[i] = b[0] - a[i];
        } 
    }

    // cout << a << "\n";
    
    bool ok = true;
    for (int i = 0; i < n-1; i++){
        if(a[i] > a[i+1]) {
            ok = false;
            break;
        }
    }

    if(ok) cout << "YES\n";
    else cout << "NO\n";
}

/*
NOTES:
1
5 1
4 0 3 1 2
3
-1 0 0 1 2



*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}

