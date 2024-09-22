// ﷽
// problem: A. Football
// URL: https://codeforces.com/problemset/problem/43/A  
// Start: 5/14/2024, 8:17:11 PM
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
    int n; cin >> n;
    map<string, int> teams;
    while(n--){
        string s; cin >> s;
        teams[s]++;
    }

    string maxTeam; int maxScore = 0;
    for(auto p : teams){
        if(p.second > maxScore){
            maxScore = p.second;
            maxTeam = p.first;
        }
    }

    cout << maxTeam;
}

/*
NOTES:

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