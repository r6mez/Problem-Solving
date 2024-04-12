// ﷽
// problem: L. Sultan Forming The Teams
// URL: https://codeforces.com/group/EhYxAu9AgP/contest/515802/problem/L  
// Start: 4/11/2024, 9:03:17 PM
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;
#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define loop (n) for (int i = 0; i < (n); i++)
#define endl '\n'



// bool checkIfAllStudentsTeamed(vi a, int n){
//     for (int i = 0; i < n; i++)
//     {
//         if(a[i] == 0) {
//             return false;
//         }
//     }
//     return true;
// } 

// void addToTeam(vi &teams, int n, int team, int maxSkillIndex, int k){
//     teams[maxSkillIndex] = team;
//     //left
//     int added = 0;
//     for (int i = maxSkillIndex; added < k && i < n; i++)
//     {
//         if(teams[i] == 0) {
//             teams[i] = team;
//             added++;
//         }
//     }

//     // right
//     added = 0;
//     for (int i = maxSkillIndex; added < k && i >= 0; i--)
//     {
//         if(teams[i] == 0) {
//             teams[i] = team;
//             added++;
//         }
//     }
// }

// int main() {
//     ios_base::sync_with_stdio(0); cin.tie(0);
//     int n, k; cin >> n >> k;
//     vi a(n); for (int i = 0; i < n; i++) cin >> a[i];
//     vi teams(n,0);
//     bool sultanRound = true;
//     while(!checkIfAllStudentsTeamed(teams,n)){
//         // find max
//         int maxSkillIndex = 0, maxSkill = INT_MIN;
//         for (int i = 0; i < n; i++)
//         {
//             if(maxSkill < a[i] && teams[i] == 0){
//                 maxSkill = a[i];
//                 maxSkillIndex = i;
//             }
//         }

//         // join teams
//         int added = 0;
//         if(sultanRound){
//             addToTeam(teams,n,1,maxSkillIndex,k);
//         } else {
//             addToTeam(teams,n,2,maxSkillIndex,k);
//         }
        
//         // switch rounds
//         sultanRound = !sultanRound;
//     }

//     for (int i = 0; i < n; i++)
//     {
//         cout << teams[i];
//     }
//     return 0;
// }


