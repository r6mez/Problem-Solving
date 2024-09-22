// ﷽
// problem: B. The Festive Evening
// URL: https://codeforces.com/problemset/problem/834/B  
// Start: 4/10/2024, 12:04:16 AM
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
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int freq[300] = {0}; bool seen[300] = {0};
    for (auto c : s) freq[c]++;
    int openedGates = 0;
    for (auto c : s)
    {
        if(seen[c] == false) {
            openedGates++;
            seen[c] = true;
        }
        if(k < openedGates){
            cout << "YES\n";
            return 0;
        }
        freq[c]--; 
        if(freq[c] == 0) openedGates--;
    }
    cout << "NO\n";
    return 0;
}