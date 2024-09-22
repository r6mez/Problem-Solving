// ﷽
// problem: F - Friends' Card Game
// URL: https://vjudge.net/contest/631754#problem/F  
// Start: 5/31/2024, 5:57:16 PM
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
#define all(v)  v.begin(), v.end()

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for(const auto& i : v) os << i << ' ';
    return os;
}
 
template<typename T>
istream& operator>>(istream& is, vector<T>& v) {
    for(auto& i : v) is >> i;
    return is;
}

void solve(){
    string sa, sb, sc;
    cin >> sa >> sb >> sc;
    queue<char> deckA, deckB, deckC;
    
    for (char c : sa) deckA.push(c);
    for (char c : sb) deckB.push(c);
    for (char c : sc) deckC.push(c);
    
    char cPlayer = 'a'; 
    
    while (true) {
        if (cPlayer == 'a') {
            if (deckA.empty()) {
                cout << "A" << endl;
                break;
            }
            cPlayer = deckA.front();
            deckA.pop();
        } else if (cPlayer == 'b') {
            if (deckB.empty()) {
                cout << "B" << endl;
                break;
            }
            cPlayer = deckB.front();
            deckB.pop();
        } else if (cPlayer == 'c') {
            if (deckC.empty()) {
                cout << "C" << endl;
                break;
            }
            cPlayer = deckC.front();
            deckC.pop();
        }
    }

}

/*
NOTES:

*/

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    int t = 1; 
    // cin >> t;
    while (t--){
        solve();
    }
    return 0;
}