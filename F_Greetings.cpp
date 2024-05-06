// ﷽
// problem: F. Greetings
// URL: https://codeforces.com/contest/1915/problem/F  
// Start: 5/6/2024, 1:47:06 PM
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
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, 
                    tree_order_statistics_node_update>;
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vll vector<long long>



void solve(){
    ll n; cin >> n;
    // first = end, second = start
    vector<pair<ll,ll>> paths(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> paths[i].second >> paths[i].first; 
    }

    sort(paths.begin(), paths.end());

    ll counter = 0;
    ordered_set<ll> os;
    for (ll i = 0; i < n; i++)
    {
        counter += os.size() - os.order_of_key(paths[i].second);
        os.insert(paths[i].second);
    }
    cout << counter << "\n"; 
}

/*
NOTES:
2 6
3 9
4 5
1 8
7 10
-2 100

5 6 8 9 10 100
4 2 1 3 7  -2
0 1 3  

endj > endi
startj < starti

6->1 
8->2 
9->1
10->0
100->5
*/


/*
Exceeds the time limit
void solve(){
    ll n; cin >> n;
    vector<pair<ll,ll>> paths(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> paths[i].second >> paths[i].first; 
    }

    sort(paths.begin(), paths.end());

    ll counter = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = i-1; j >= 0; j--)
        {
            if(paths[i].second < paths[j].second && paths[i].first > paths[j].first)
                counter++;
        }
    }

    cout << counter << "\n"; 
}
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