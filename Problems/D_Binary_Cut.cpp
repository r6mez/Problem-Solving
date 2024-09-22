// ﷽
// problem: D. Binary Cut
// URL: https://codeforces.com/contest/1971/problem/D  
// Start: 5/10/2024, 4:51:33 PM
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
    int cuts = 1;

    bool isSaw = false;
    for (int i = 0; i < s.size()-1; i++)
    {
        if(s[i] == '1' && s[i+1] == '0')
        {
            cuts++;
        } 
        else if(s[i] == '0' && s[i+1] == '1'){
            if(isSaw) cuts++;
            isSaw = true;
        }
    }
    cout << cuts << "\n";
}

/*
NOTES:
1010101010
1 01 0 1 0 1 0 1 0

10 10 10 10 10


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