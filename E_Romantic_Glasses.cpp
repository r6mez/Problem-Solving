// ﷽
// problem: E. Romantic Glasses
// URL: https://codeforces.com/contest/1915/problem/E  
// Start: 5/6/2024, 1:11:56 PM
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
    
    ll alternatingSum[n+1] = {0};
    map<ll, ll> freqOfSums;
    freqOfSums[0] = 1;
    bool exist = false;

    for (int i = 1; i <= n; i++)
    {
        ll cup; cin >> cup;
        if(i%2 == 0) {
            alternatingSum[i] = alternatingSum[i-1] - cup;
        } else {
            alternatingSum[i] = alternatingSum[i-1] + cup;
        }
        freqOfSums[alternatingSum[i]]++;
        if(freqOfSums[alternatingSum[i]] >= 2) exist = true;
    }

    if(exist) cout << "YES\n";
    else cout << "NO\n";
}

/* Exceeds the time limit */
// void solve(){
//     int n; cin >> n;
    
//     ll sumOdd[n+1] = {0};
//     ll sumEven[n+1] = {0};
    
//     for (int i = 1; i <= n; i++)
//     {
//         ll cup; cin >> cup;
//         if(i%2 == 0) {
//             sumEven[i] = sumEven[i-1] + cup;
//             sumOdd[i] = sumOdd[i-1];
//         }else {
//             sumOdd[i] = sumOdd[i-1] + cup;
//             sumEven[i] = sumEven[i-1];
//         }
//     }

//     bool exist = false;
//     for (int i = 1; i < n+1; i++)
//     {
//         for (int j = i+1; j < n+1; j++)
//         {
//             if((sumOdd[j] - sumOdd[i-1]) == (sumEven[j] - sumEven[i-1])){
//                 exist = true;
//                 break;
//             }
//         }
//         if(exist) break;
//     }
    
//     if(exist) cout << "YES\n";
//     else cout << "NO\n";
// }


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