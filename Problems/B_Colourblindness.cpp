// ﷽
// problem: B. Colourblindness
// URL: https://codeforces.com/problemset/problem/1722/B  
// Start: 5/9/2024, 9:00:25 PM
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
    string s1,s2; cin >> s1 >> s2;
    for (int i = 0; i < n; i++)
    {
        if(s1[i] == 'G' || s1[i] == 'B') s1[i] = 'C';
        if(s2[i] == 'G' || s2[i] == 'B') s2[i] = 'C';
    }
    if(s1 == s2) cout << "YES\n";
    else cout << "NO\n";
}

/*
NOTES:

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