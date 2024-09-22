// ﷽
// problem: B. Notepad#
// URL: https://codeforces.com/problemset/problem/1766/B  
// Start: 5/13/2024, 10:41:48 PM
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
    string s; cin >> s;
    map<string, int> substrings;
    
    for (int i = 0; i < n-1; i++)
    {
        string newSubString = s.substr(i, 2);
        substrings[newSubString]++;
        if(substrings[newSubString] > 1) {cout << "YES\n"; return;};
        if(i < n-2 && s[i] == s[i+1] && s[i+1] == s[i+2]) i++;
    }
    cout << "NO\n";
}

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