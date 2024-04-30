// ﷽
// problem: H. Priority_Queue
// URL: https://codeforces.com/group/isP4JMZTix/contest/392597/problem/H  
// Start: 4/30/2024, 5:04:05 AM
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
    queue<ll> deck;
    for (int i = 0; i < n; i++)
    {
        ll card; cin >> card; 
        deck.push(card);
    }

    priority_queue<ll> bonusDeck;
    ll power = 0;
    while(!deck.empty()){
        if(deck.front() != 0){
            bonusDeck.push(deck.front());
        } 
        else 
        {
            if(!bonusDeck.empty()){
                power += bonusDeck.top();
                bonusDeck.pop();
            }
        }
        deck.pop();
    }
    
    cout << power << "\n";
}

/*
NOTES:
Deck on n 
Hero -> power of 0
bonus -> power of > 0

you can:
take card
    -> bonus -> add to bonus deck
    -> hero -> take the top card of the bonus deck and replace it with the power of the hero -> delete bonus

maximize total power



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