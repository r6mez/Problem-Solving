/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all it remained were fields of dreamless solitude.
*/
// C. Matching Arrays
// URL: https://codeforces.com/problemset/problem/1896/C
// Time: 2/4/2025, 8:35:44 PM
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
    int n, x; cin >> n >> x;
    vi a(n), b(n); cin >> a >> b;
    vi copyA(a);
    sort(all(copyA));
    sort(all(b));
    
    if(x == 0){
        if(copyA[0] != b[0]){
            cout << "YES\n";
            cout << b << "\n";
        } else {
            cout << "NO\n";
        }
        return;
    }

    int idx = lower_bound(all(b), copyA[x-1]) - b.begin();
    cout << idx << "\n";
    if(idx == x){
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }


}

/*
NOTES:
2 3 4
1 2 4

2 3 4
1 2 4 

2 4 5 6 6 
1 1 2 5 6


*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}

