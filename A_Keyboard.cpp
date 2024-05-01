// ﷽
// problem: A. Keyboard
// URL: https://codeforces.com/problemset/problem/474/A  
// Start: 5/1/2024, 8:24:47 AM
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
    char c; cin >> c;
    string s; cin >> s;

    vector<string> keyboard = {"qwertyuiop", "asdfghjkl;", "zxcvbnm,./"};

    for (int i = 0; i < s.size(); i++)
    {
        for (int j = 0; j < 3; j++)
        {   
            int buttonIndex;
            if((buttonIndex = keyboard[j].find(s[i])) != string::npos){
                cout << (c == 'R'? keyboard[j][buttonIndex-1] : keyboard[j][buttonIndex+1]);
            }
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