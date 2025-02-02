// I. Falfoul and Zanqoun's Wormy Lunch
// URL: https://codeforces.com/gym/584099/problem/I
// Time: 2/1/2025, 1:32:33 PM
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
int n;
cin>>n;
vector<int>piles(n);
vector<int> pre_sum (n,0);
  for(int i=0 ; i<n ; i++){
    cin>>piles[i];
    if(i>=1)
        pre_sum[i]+=(pre_sum[i-1]+piles[i]);
    else 
        pre_sum[i]=piles[i];
  }

  int Nworms, res;
  cin>>Nworms;
  vector<int> worms(Nworms);
  for(int i=0 ; i<Nworms ; i++){
    cin>>worms[i];
    int l=0, r=n-1, mid;
    while(l<=r){
        mid = (r+l)/2;
        if(pre_sum[mid]>=worms[i]){
            res = mid;
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    cout << res+1 << endl;
  }
  
     

}

/*
NOTES:

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
      // cin >> t;
   // while (t--) 
   Solve();
    return 0;
}