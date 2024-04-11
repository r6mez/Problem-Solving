// ﷽
// problem: A. Winner
// URL: https://codeforces.com/contest/2/problem/A  
// Start: 4/11/2024, 5:22:27 PM
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
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


// This code doesn't work if there's a winner who looses points after gaining the max score
// int main() {
//     ios_base::sync_with_stdio(0); cin.tie(0);
//     int n; cin >> n;
//     map<string, int> players;
//     pair<string,int> winner;
//     int maxScore = INT_MIN;
//     while (n--)
//     {
//         pair<string, int> input; cin >> input.first >> input.second;
//         players[input.first] += input.second;
        
//         if(players[input.first] > winner.second){
//             winner.first = input.first;
//             winner.second =  players[input.first];
//             maxScore = winner.second;
//         }
//     }
//     cout << winner.first << "\n";
//     return 0;
// }

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<pair<string,int>> rounds(n);
    map<string, int> players;

    for (int i = 0; i < n; i++)
    {
        cin >> rounds[i].first >> rounds[i].second;
        players[rounds[i].first] += rounds[i].second;
    }
    
    set<string> winners;
    int m = INT_MIN;
    for(auto &player : players){
        if(player.second > m){
            m = player.second;
            winners.clear();
            winners.insert(player.first);
        } else if(player.second == m) {
            winners.insert(player.first);
        }
    }

    if(winners.size() > 1){
        players.clear();
        for(auto &round: rounds){
            players[round.first] += round.second;
            if(players[round.first] >= m && winners.count(round.first) == 1){
                winners.clear();
                winners.insert(round.first);
                break;
            }
        }    
    }

    cout << *winners.begin();
    return 0;
}