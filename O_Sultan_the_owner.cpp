// ﷽
// problem: O. Sultan, the owner
// URL: https://codeforces.com/group/EhYxAu9AgP/contest/515802/problem/O  
// Start: 4/11/2024, 10:25:00 PM
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
    int q; cin >> q;
    while (q--){
        int n, k; cin >> n >> k;
        vi a(n); 
        int minPrice = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] < minPrice) minPrice = a[i];
        }

        bool isPos = true;
        int newPrices = minPrice + k;
        for (int i = 0; i < n; i++)
        {
            if(abs(a[i] - newPrices) > k){
                isPos = false;
                break;
            }
        }
        if(isPos) cout << newPrices << "\n";
        else cout << -1 << "\n";        
    }
    return 0;
}
