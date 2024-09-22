// ﷽
// problem: A. Vlad and the Best of Five
// URL: https://codeforces.com/contest/1926/problem/A  
// Start: 4/25/2024, 8:16:07 PM
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
    int t; cin >> t;
    while (t--){
        int a = 0, b = 0;
        string s; cin >> s;
        for(char c: s){
            if(c == 'A') a++;
            else b++;
        }
        cout << (a>b? "A" : "B") << "\n";
    }
    return 0;
}
