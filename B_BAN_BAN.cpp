// ﷽
// problem: B. BAN BAN
// URL: https://codeforces.com/problemset/problem/1747/B  
// Start: 5/5/2024, 5:40:26 PM
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
    if(n == 1) {cout << "1\n1 2\n"; return;}

    int m = 0;
    vector<pair<int,int>> v;
    for (int i = 0; i < ceil(n/2.0); i++)
    {
        int indexOfLast = n*3-i*3;
        int indexOfB = i*3+1;
        v.push_back(make_pair(indexOfB,indexOfLast));
        m++;
    }

    cout << m << "\n";
    for(auto p : v) cout << p.first << " " << p.second << "\n";
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
