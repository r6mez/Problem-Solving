// ﷽
// problem: B. Shifts and Sorting
// URL: https://codeforces.com/contest/1969/problem/B  
// Start: 4/29/2024, 5:53:53 AM
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


void solve() {
    string s;
    cin >> s;
    ll n = s.size();
    ll onesBefore = 0, cost = 0;

    for (ll i = 0; i < n; i++)
    {   
        if(s[i] == '1') onesBefore++; 
        else if(onesBefore != 0) cost += onesBefore + 1;
    }

    cout << cost << "\n";
}

/*
NOTES:

01101001
3
00111001
4
00011101
4
00001111
= 11
counter = 2 
cost = 3
counter = 3
cost = 4 

101011
2
011011
3
001111
 = 5


11000
counter = 2
cost = 3
cost = 6
cost = 0



*/



int main() {
    // ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}


// working perfect burte force solution but exceeds time limit.

// string cyclicString(string s, ll start, ll end){
//     char endChar = s[end];
//     for (int i = end; i > start; i--)
//     {
//         s[i] = s[i-1];
//     }
//     s[start] = endChar;
//     return s;
// }

// void solve(){
//     string q; cin >> q;
//     string s = q; 

//     sort(q.begin(), q.end());
//     if(s == q) {cout << 0 << "\n"; return;}

//     ll cost = 0;
//     while (s != q){
//         bool oneIsFound = false;
//         ll oneIndex = 0;
//         ll zeroIndex = 0;
//         for (ll i = 0; i < s.size(); i++)
//         {
//             if(oneIsFound == false && s[i] == '1') {
//                 oneIsFound = true;
//                 oneIndex = i;
//                 continue;
//             }

//             if(oneIsFound == true && s[i] == '0') {
//                 zeroIndex = i;
//                 cost += (zeroIndex - oneIndex + 1);
//                 s = cyclicString(s,oneIndex,zeroIndex);
//                 break;
//             }
//         }
//     }

//     cout << cost << "\n";
// }


