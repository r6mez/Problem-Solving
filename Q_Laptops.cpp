// ﷽
// problem: Q. Laptops
// URL: https://codeforces.com/group/isP4JMZTix/contest/392597/problem/Q  
// Start: 5/1/2024, 5:38:12 AM
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
    set<pair<int,int>> pq;
    for (int i = 0; i < n; i++)
    {
        int p,q; cin >> p >> q;
        pq.emplace(make_pair(p,q));
    }
    bool found = false;
    
    for (auto it = pq.begin(); it != --pq.end(); )
    {
        int firstQ = (*it).second, secondQ = (*(++it)).second;
        if(firstQ > secondQ) {
            found = true; 
            break;
        }
    }

    if(found) cout << "Happy Alex";
    else cout << "Poor Alex";
}

/*
3
1 2 
2 4 
5 6
3 2


1 2 
2 4 
3 2
5 6

*/

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    int t = 1; 
    // cin >> t;
    while (t--){
        solve();
    }
    return 0;
}