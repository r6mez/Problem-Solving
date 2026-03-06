// J. Falfoul's Nice Number Hunt
// URL: https://codeforces.com/gym/584099/problem/J
// Time: 2/1/2025, 1:32:34 PM
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
int nice (int n){
    if(n==6 || n==9 || n==99 || n==69 || n==96 || n== 66)
    return n;

    n++;
    return nice(n);
}

void Solve() {
int n ; 
cin>>n ;
cout<<nice(n)<<endl;
}

/*
NOTES:

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t;
    cin>>t;
    while (t--) Solve();
    return 0;
}