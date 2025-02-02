// C. Shakshouka's Subsegment Search
// URL: https://codeforces.com/gym/584099/problem/C
// Time: 2/1/2025, 1:32:27 PM
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


void Solve() {
    int n; cin >> n;
    vi a(n); cin >> a;

    int i = 0, j = n-1, mn = 1, mx = n;
    while (i <= j){
        if(a[j] == mn){
            j--;
            mn++;
        } else if (a[j] == mx) {
            j--;
            mx--;
        } else if (a[i] == mn){
            i++;
            mn++;
        } else if(a[i] == mx){
            i++;
            mx--;
        } else {
            break;
        }
    } 

    if(i <= j) cout << i+1 << " " << j+1 << "\n";
    else cout << "-1\n";
}

/*
NOTES:

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Solve();
    return 0;
}