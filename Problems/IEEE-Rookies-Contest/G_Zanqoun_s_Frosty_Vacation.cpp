// G. Zanqoun's Frosty Vacation
// URL: https://codeforces.com/gym/584099/problem/G
// Time: 2/1/2025, 1:32:31 PM
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
    int n, k, q, c=0, res=0;
    cin >> n >> k >> q;
    vector<int> a(n);
    cin >> a;
    for(int i=0; i<n; ++i){
        if(a[i]<=q){
            c++;
        }else{
            if(c>=k)
            {c = c-k+1;
            res +=(c*(c+1))/2;}
            c=0;
        }
    }
    if(c>=k){
        c = c-k+1;
        res +=(c*(c+1))/2;
    }
    cout << res<< "\n";
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