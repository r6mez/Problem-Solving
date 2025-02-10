/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all it remained were fields of dreamless solitude.
*/
// C2. Skibidus and Fanum Tax (hard version)
// URL: https://codeforces.com/contest/2065/problem/C2
// Time: 2/9/2025, 4:51:23 PM
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

    sort(all(b));

    int minStart = a[0];
    for (int j = 0; j < m; j++){
        minStart = min(minStart, b[j] - a[0]);
    }
    a[0] = minStart;


    for (int i = 1; i < n; i++){
        if(a[i] == a[i-1]) continue;
        auto it = lower_bound(all(b), a[i-1] + a[i]);

        if(it == b.end()) {
            continue;
        }

        int j = it - b.begin();
        if(a[i-1] > a[i] || a[i] > b[j] - a[i]) a[i] = b[j] - a[i];
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
4 3
2 4 6 5
1 6 8 -
-1 2 2 5
6 1 8

a[i-1] <= b[j] - a[i]
a[i-1] + a[i] <= b[j] 

check if the operation will decrease the value 
of a[i] as much as possible but still be above or equal a[i-1]


if a[i-1] > a[i]  
let's find the least b[j] that gives us b[j] - a[i] 
that's just above or equal a[i-1]
*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}

