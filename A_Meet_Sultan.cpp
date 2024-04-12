// ﷽
// problem: A. Meet Sultan!
// URL: https://codeforces.com/group/EhYxAu9AgP/contest/515802/problem/0  
// Start: 4/11/2024, 7:00:15 PM
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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s;
    int counter = 0;
    for (int i = 0; i < s.size(); )
    {
        if(s[i] == 'h' && s[i+1] == 'z' && s[i+2] == 'n' && s[i+3] == 'u') {
            counter++;
            i += 4; // hznu2huzu
        } else i++;
    }
    cout << counter;
    
    return 0;
}
