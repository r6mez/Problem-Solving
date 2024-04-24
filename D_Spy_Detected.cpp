// ﷽
// problem: D. Spy Detected!
// URL: https://codeforces.com/group/isP4JMZTix/contest/380288/problem/D  
// Start: 4/23/2024, 7:19:04 PM
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
    while(t--){
        int n; cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int index = 0;
        for (int i = 1; i < n-1; i++)
        {
            if(a[i] != a[i-1] && a[i] != a[i+1]){
                index = i; 
                break;
            }
            if(i == 1 && a[i-1] != a[i] && a[i-1] != a[i+1]){
                index = 0;
                break;
            }
            if(i == n-2 && a[i+1] != a[i] && a[i+1] != a[i-1]){
                index = i+1;
                break;
            }
        }
        
        cout << index+1 << "\n";
    }
    return 0;
}
