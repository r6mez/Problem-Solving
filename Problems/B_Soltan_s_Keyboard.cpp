// ﷽
// problem: B - Soltan's Keyboard
// URL: https://vjudge.net/contest/630348#problem/B  
// Start: 5/23/2024, 5:35:21 PM
#include <iostream>
#include <algorithm>
using namespace std;


void solve(){
    string op; cin >> op;
    string s = "";
    for (int i = 0; i < op.size(); i++)
    {
        if(op[i] == '0') s.push_back('0');
        else if (op[i] == '1') s.push_back('1');
        else if (op[i] == 'B' && !s.empty())s.pop_back();
    }
    cout << s;    
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