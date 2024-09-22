// ﷽
// problem: F. Multiset
// URL: https://codeforces.com/group/isP4JMZTix/contest/392597/problem/F  
// Start: 4/29/2024, 11:54:09 PM
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vll vector<long long>

void solve(){
    int n; cin >> n;
    vi a(n);
    for(int &i : a) cin >> i;

    int maxK = 0;
    for (int k = 1; k <= n; k++)
    {
        multiset<int> mst(a.begin(),a.end());
        for (int i = 1; i <= k; i++)
        {
            auto it = mst.upper_bound(k-i+1);
            if(it == mst.begin()) break;
            mst.erase(--it);
            if(!mst.empty()){
                int num = *mst.begin();
                mst.erase(mst.begin());
                mst.insert(num+k-i+1);
            }
        }
        if(mst.size() + k == n) maxK = k;
    }
    cout << maxK << "\n";
}

/*
NOTES:
array of num
alice choose k (stages)
each stage alice plays then bob
in stage i
-> alice remove num <= k-i+1
-> bob adds k-i+1 to any num
if(alice can't delete) he loses
if(k ends and alice didn't lose) alice wins
max k that alice wins
-------------

3
1 1 2
K = 1 i = 1 | 2 2 

K = 2 i = 1 | 1 3 
K = 2 i = 2 | 4 

K = 3 i = 1 | 1 4 
K = 3 i = 2 | 6 
K = 3 i = 3 | 6 // can't delete 
2

4
4 4 4 4
K = 4 i = 1 | 4 4 8 
0

1
1
K = 1 i = 1 | 
1

5
1 3 2 1 1
K = 1 i = 1 | 1 2 2 3 
K = 2 i = 1 | 1 1 3 3 
K = 2 i = 2 | 2 3 3 
K = 3 i = 1 | 1 1 2 4 
K = 3 i = 2 | 1 3 4 
K = 3 i = 3 | 4 4 
K = 4 i = 1 | 1 1 2 5 
K = 4 i = 2 | 1 4 5 
K = 4 i = 3 | 5 6 
K = 5 i = 1 | 1 1 2 6 
K = 5 i = 2 | 1 5 6 
K = 5 i = 3 | 6 8 
3

*/

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    int t = 1; 
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}