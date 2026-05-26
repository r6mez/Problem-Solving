// B. GCD Every Where
// URL: https://codeforces.com/group/Rilx5irOux/contest/686782/problem/B
// Time: 5/25/2026, 2:35:27 PM
#include <bits/stdc++.h>
#include <map>
using namespace std;
#define int         long long
#define vi          vector<int>
#define pii         pair<int, int>
#define all(v)      v.begin(), v.end()
#define finish(s)   { cout << s << "\n"; return; }
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { cin.tie(nullptr)->sync_with_stdio(false); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007, INF = 2e18;
    vi v(1e5 +100);

void solve() {
int n;
cin>>n;

for (int i=0; i<n; i++) {
cout<<v[i]<<" ";
}
}

/*

*/

signed main() {
    // UseFile();
    FastIO();
        int n;
    n=1e5+10;
    v[0]=2;
    map<int, int>m;
    m[2]=1;
    int cur=3;
    for(int i =1 ; i <n;i++)
    {v[i]=v[i-1]*2;
        m[v[i]]=1;
           m[cur]=1;
 
    v[i+1]=cur;
    cur+=2;
    i++;
    }

    
    int t = 1;
    cin >> t;
    while (t--) solve();
}