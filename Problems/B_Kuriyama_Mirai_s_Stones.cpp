// ﷽
// problem: B. Kuriyama Mirai's Stones
// URL: https://codeforces.com/problemset/problem/433/B
// Start: 4/9/2024, 10:40:09 PM
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
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
#define loop(n) for (int i = 0; i < (n); i++)
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    ll a[n];
    loop(n) cin >> a[i];

    // freq of not arranged
    ll freqOfNotArranged[n+1] = {0};
    freqOfNotArranged[1] = a[0];
    for (int i = 0; i < n+1; i++) freqOfNotArranged[i+1] = freqOfNotArranged[i] + a[i]; 


    //freq of arranged
    sort(a, a+n);
    ll freqOfArranged[n+1] = {0};
    freqOfArranged[1] = a[0];
    for (int i = 0; i < n+1; i++) freqOfArranged[i+1] = freqOfArranged[i] + a[i]; 



    int m; cin >> m;
    while(m--){
        int t,l,r; cin >> t >> l >> r;
        if(t == 1) cout << (freqOfNotArranged[r] - freqOfNotArranged[l-1]) << endl;
        else cout << (freqOfArranged[r] - freqOfArranged[l-1]) << endl;
    } 
    return 0;
}

/*             n  n+1
0 1 2 3  4  5  6  7
0 6 8 15 17 24 28 
0 2 6 12 19 26 28
*/