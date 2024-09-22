// ﷽
// problem: N. Sultan's Birthday
// URL: https://codeforces.com/group/EhYxAu9AgP/contest/515802/problem/N  
// Start: 4/11/2024, 8:39:59 PM
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

int n; 
vector<int> a;
ll sum(ll i = 0, ll current_sum = 0){
    if(i == n) return current_sum;
    ll take = sum(i + 1, current_sum | a[i]);
    ll leave = sum(i + 1, current_sum);
    return take + leave;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    cout << sum() << endl;
    return 0;
}