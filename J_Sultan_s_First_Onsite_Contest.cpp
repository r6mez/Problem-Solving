// ﷽
// problem: J. Sultan's First Onsite Contest
// URL: https://codeforces.com/group/EhYxAu9AgP/contest/515802/problem/J  
// Start: 4/11/2024, 7:38:25 PM
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
    int x, y;
    cin >> x >> y;
    string s; cin >> s;
    for(char c: s){
        if(c == 'U') y += 1;
        else if (c == 'D') y -= 1;
        else if (c == 'L') x -= 1;
        else if (c == 'R') x += 1;
    }
    cout << x  << " " << y;
    return 0;
}
