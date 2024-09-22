// ﷽
// problem: A. Square String?
// URL: https://codeforces.com/problemset/problem/1619/A  
// Start: 5/6/2024, 6:49:08 PM
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
    string s; cin >> s;
    if(s.size()%2 != 0) {
        cout << "NO\n";
        return;
    }

    for (int i = 0; i <= s.size()/2 - 1; i++)
    {
        if(s[i] != s[s.size()/2 + i]){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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