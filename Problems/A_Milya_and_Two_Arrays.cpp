/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all it remained were fields of dreamless solitude.
*/
// A. Milya and Two Arrays
// URL: https://codeforces.com/contest/2059/problem/A
// Time: 2/5/2025, 10:13:35 PM
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
    set<int> a, b;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        a.insert(x);
    }
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        b.insert(x);
    }

    if(a.size() + b.size() - 1 >= 3){
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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

