// ﷽
// problem: C. Everything Nim
// URL: https://codeforces.com/contest/1966/problem/C  
// Start: 4/27/2024, 6:37:32 AM
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
    ll n; cin >> n;
    vll a(n);
    for(ll &i : a) cin >> i;
    a.push_back(0);
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(), a.end()), a.end()); // erases all duplicates
    n = a.size();

    ll currentPlayer = 1;
    for (ll i = n-2; i > 0; i--)
    {
        if(a[i]-a[i-1] == 1) currentPlayer = !currentPlayer;
        else currentPlayer = 1;
    }
    cout << (currentPlayer? "Alice\n" : "Bob\n");
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


/*
NOTES:
if(there's difference between each number > 1)
    alice can make a move than makes him win

8
5 7 2 9 6 3 3 2
2 3 5 6 7 9
= 6

2 2 3 3 5 6 7 9
0 0 1 1 3 4 5 7 Alice -2
0 0 0 0 2 3 4 7 Bob -1
0 0 0 0 0 1 2 5 Alice -2
0 0 0 0 0 0 1 4 Bob -1
0 0 0 0 0 0 0 3 Alice -1
0 0 0 0 0 0 0 0 Bob -3

0 0 1 1 3 4 5 7 Alice -2
0 0 0 0 2 3 4 7 Bob -1
0 0 0 0 1 2 3 6 Alice -1 // Here
0 0 0 0 0 1 2 5 Bob -1
0 0 0 0 0 0 1 4 Alice -1
0 0 0 0 0 0 0 4 Bob -1
0 0 0 0 0 0 0 0 Alice -4


*/