// ﷽
// problem: C. Vlad and a Sum of Sum of Digits
// URL: https://codeforces.com/contest/1926/problem/C  
// Start: 4/25/2024, 9:12:40 PM
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


ll SumOfDigits(ll n){
    ll sum = 0;
    while (n != 0){
        sum += n%10;
        n /= 10;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll x = 2*10*10*10*10*10+1;
    ll sum[x] = {0};
    for (ll i = 1; i <= x; i++)
    {
        sum[i] = sum[i-1] + SumOfDigits(i);
    }

    ll t; cin >> t;
    while (t--){
        ll n; cin >> n;
        cout << sum[n] << "\n";
    }
    return 0;
}

/*

*/
